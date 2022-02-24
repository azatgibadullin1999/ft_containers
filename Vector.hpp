/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:51:27 by root              #+#    #+#             */
/*   Updated: 2022/02/22 15:57:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "iterators/VectorIterator.hpp"
# include <iostream>
# include <vector>
# include <memory>
# include <iterator>
# include <cstddef>
# include <limits>
# include <exception>
# include "utils.hpp"

# define nullptr NULL

namespace ft {


template <typename T, typename Allocator = std::allocator<T> >
class vector {

	public :
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ft::vector_iterator<pointer>				iterator;
		typedef ft::vector_iterator<const_pointer>			const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private :
		size_type		_size;
		size_type		_capacity;
		pointer			_vec;
		allocator_type	_alloc;

	public :

			//	MEMBER FUNCIONS

		vector() :
			_size(0),
			_capacity(0),
			_vec(nullptr),
			_alloc(allocator_type()) { }

		explicit vector(const allocator_type alloc) :
			_size(0),
			_capacity(0),
			_vec(nullptr),
			_alloc(alloc) { } 

		explicit vector(size_type count,
						const_reference value = T(),
						allocator_type alloc = allocator_type()) :
							_alloc(alloc) {
								__hidden_constructor(count, value, true_type());
							}

		template <typename InputIt>
		vector(InputIt first,
				InputIt last,
				const allocator_type alloc = allocator_type()) :
					_alloc(alloc) {
						typedef typename ft::is_integral<InputIt>::type		integral;
						__hidden_constructor(first, last, integral());
					}

		vector(const vector &other) :
			_size(other._size),
			_capacity(other._capacity),
			_alloc(other._alloc) {
				this->_vec = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(&this->_vec[i], other[i]);
			}

		~vector() {
			if (this->_capacity != 0) {
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_vec[i]);
				this->_alloc.deallocate(this->_vec, this->_capacity);
			}
		}

		vector	&operator = (const vector &other) {
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_vec[i]);
			this->_size = 0;
			insert(this->begin(), other.begin(), other.end());
			return *this;
		}

		void	assign(size_type count, const_reference value) {
			__hidden_assign(count, value, true_type());
		}

		template <typename InputIt>
		void	assign(InputIt first, InputIt last) {
			typedef typename ft::is_integral<InputIt>::type		integral;
			__hidden_assign(first, last, integral());
		}

			//	ELEMENT ACCESS

		reference		at(size_type pos) {
			if (pos >= this->_size)
				throw std::out_of_range("you go out of range");
			return this->_vec[pos];
		}

		const_reference	at(size_type pos) const {
			if (pos >= this->_size)
				throw std::out_of_range("you go out of range");
			return this->_vec[pos];
		}

		reference		operator [] (size_type pos) { return this->_vec[pos]; }

		const_reference	operator [] (size_type pos) const { return this->_vec[pos]; }

		reference		front() { return this->_vec[0]; }

		const_reference	front() const { return this->_vec[0]; }

		reference		back() { return this->_vec[this->_size - 1]; }

		const_reference	back() const { return this->_vec[this->_size - 1]; }

		pointer			data() { return (this->_vec); }

		const_pointer	data() const { return (this->_vec); }

			//	ITERATORS

		iterator				begin() { return iterator(this->_vec); }

		const_iterator			begin() const { return const_iterator(this->_vec); }

		iterator				end() { return iterator(&this->_vec[this->_size]); }

		const_iterator			end() const { return const_iterator(&this->_vec[this->_size]); }

		reverse_iterator		rbegin() { return reverse_iterator(this->end()); }

		const_reverse_iterator	rbegin() const { return const_revese_iterator(this->end()); }

		reverse_iterator		rend() { return reverse_iterator(this->begin()); }

		const_reverse_iterator	rend() const { return const_reverse_iterator(this->begin()); }

			//	CAPACITY

		bool		empty() const { return !static_cast<bool>(this->_size); }

		size_type	size() const { return this->_size; }

		size_type	max_size() const {
			return std::min((size_type) std::numeric_limits<difference_type>::max(),
						std::numeric_limits<size_type>::max() / sizeof(value_type));
		}


		void		reserve(size_type new_cap) {
			pointer		new_vec;

			if (new_cap > this->_capacity) {
				new_vec = this->_alloc.allocate(new_cap);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(&new_vec[i], this->_vec[i]);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_vec[i]);
				this->_alloc.deallocate(this->_vec, this->_capacity);
				this->_vec = new_vec;
				this->_capacity = new_cap;
			}
		}

		size_type	capacity() const { return this->_capacity; }

			//	MODIFIERS

		void		clear() {
			for (size_type i = 0; i < this->_size; i++) {
				this->_alloc.destroy(&this->_vec[i]);
			}
			this->_size = 0;
		}

		iterator	insert(iterator pos, const_reference value) {
			difference_type	diff = std::distance(this->begin(), pos);

			insert(pos, 1, value);
			return this->begin() + diff;
		}

		void		insert(iterator pos, size_type count, const_reference value) {
			__hidden_insert(pos, count, value, true_type());
		}

		template <typename InputIt>
		void		insert(iterator pos, InputIt first, InputIt last) {
			typedef typename is_integral<InputIt>::type		integral;
			__hidden_insert(pos, first, last, integral());
		}

		iterator	erase(iterator pos) {
			erase(pos, pos + 1);
			return pos;
		}

		iterator	erase(iterator first, iterator last) {
			difference_type	count = std::distance(first, last);
			difference_type diff = std::distance(this->begin(), first);


			__insert(&this->_vec[diff], &this->_vec[count + diff], &this->_vec[this->_size - 1]);
			for (size_type i = this->_size - count - 1; i < this->_size; i++)
				this->_alloc.destroy(&this->_vec[i]);
			this->_size -= count;
			return first;
		}

		void		push_back(const_reference value) {
			insert(this->end(), value);
		}

		void		pop_back() {
			this->_alloc.destroy(&this->_vec[--this->_size]);
		}

		void		resize(size_type count, value_type value = T()) {
			if (count > this->_capacity)
				this->reserve(this->_capacity << 1 > count ? this->_capacity << 1 : count);
			if (count > this->_size) {
				for (size_type i = this->_size; i < count; i++)
					this->_alloc.construct(&this->_vec[i], value);
			}
			else {
				for (size_type i = count; i < this->_size; i++)
					this->_alloc.destroy(&this->_vec[i]);
			}
			this->_size = count;
		}

		void		swap(vector &other) {
			std::swap(this->_capacity, other._capacity);
			std::swap(this->_size, other._size);
			std::swap(this->_vec, other._vec);
		}

	private :

		void	__reverse_insert(pointer dst, pointer src_begin, pointer src_end) {
			while (src_begin >= src_end) {
				this->_alloc.construct(dst, *src_begin);
				--src_begin;
				--dst;
			}
		}

		void	__insert(pointer dst, pointer src_begin, pointer src_end) {
			while (src_begin <= src_end) {
				this->_alloc.construct(dst, *src_begin);
				++src_begin;
				++dst;
			}
		}

		void	__hidden_constructor(size_type count, const_reference value, true_type) {
			this->_size = count;
			this->_capacity = count;
			this->_vec = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(&this->_vec[i], value);
		}

		template <typename InputIt>
		void	__hidden_constructor(InputIt first, InputIt last, false_type) {
			difference_type	count = std::distance(first, last);
			this->_size = count;
			this->_capacity = count;
			this->_vec = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < static_cast<size_type>(count); i++)
				this->_alloc.construct(&this->_vec[i], *first++);
		}

		void	__hidden_insert(iterator pos, size_type count, const_reference value, true_type) {
			difference_type	diff = std::distance(this->begin(), pos);

			if (count + this->_size > this->_capacity)
				this->reserve(this->_capacity << 1 > this->_size + count ? this->_capacity << 1 : this->_size + count);
			__reverse_insert(&this->_vec[count + this->_size - 1], &this->_vec[this->_size - 1], &this->_vec[diff]);
			for (size_type i = diff; i < diff + count; i++) {
				this->_alloc.construct(&this->_vec[i], value);
			}
			this->_size += count;
		}

		template <typename InputIt>
		void	__hidden_insert(iterator pos, InputIt first, InputIt last, false_type) {
			difference_type count = std::distance(first, last);
			difference_type	diff = std::distance(this->begin(), pos);

			if (count + this->_size > this->_capacity)
				this->reserve(this->_capacity << 1 > this->_size + count ? this->_capacity << 1 : this->_size + count);
			__reverse_insert(&this->_vec[count + this->_size - 1], &this->_vec[this->_size - 1], &this->_vec[diff]);
			for (size_type i = diff; i < static_cast<size_type>(count) + diff; i++) {
				this->_alloc.construct(&this->_vec[i], *first++);
			}
			this->_size += count;
		}

		void	__hidden_assign(size_type count, const_reference value, true_type) {
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_vec[i]);
			this->_size = 0;
			this->reserve(count);
			for (size_type i = 0; i < count; i++)
				this->_alloc.construct(&this->_vec[i], value);
			this->_size = count;
		}

		template <typename InputIt>
		void	__hidden_assign(InputIt first, InputIt last, false_type) {
			difference_type	count = std::distance(first, last);

			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_vec[i]);
			this->_size = 0;
			this->reserve(count);
			for (size_type i = 0; i < static_cast<size_type>(count); i++)
				this->_alloc.construct(&this->_vec[i], *first++);
			this->_size = count;
		}


} ;

template <typename T, typename Alloc>
bool	operator == (const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc>&rhs) {
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && (lhs.size() == rhs.size());
}

template <typename T, typename Alloc>
bool	operator != (const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc>&rhs) {
	return !(lhs == rhs);
}

template <typename T, typename Alloc>
bool	operator < (const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc>&rhs) {
	return ft::lexicographic_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T, typename Alloc>
bool	operator > (const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc>&rhs) {
	return (rhs < lhs);
}

template <typename T, typename Alloc>
bool	operator >= (const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc>&rhs) {
	return !(lhs < rhs);
}

template <typename T, typename Alloc>
bool	operator <= (const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc>&rhs) {
	return !(lhs > rhs);
}


}


#endif
