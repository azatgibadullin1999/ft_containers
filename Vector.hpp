/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:51:27 by root              #+#    #+#             */
/*   Updated: 2021/12/03 14:55:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <unistd.h>
# include <string.h>
# include <iostream>
# include <vector>
# include <memory>
# include <iterator>
# include <cstddef>
# include <limits>
# include <exception>
# include "utils.hpp"

# define nullptr (void *)0

namespace ft {


template <typename T>
class VectorIterator : public std::iterator<std::random_access_iterator_tag, T> {

	private :

		typedef ft::iterator_traits<VectorIterator>	iterator_traits;

	public :

			// TYPDEF

		typedef typename iterator_traits::iterator_category	iterator_category;
		typedef typename iterator_traits::value_type		value_type;
		typedef typename iterator_traits::reference			reference;
		typedef typename iterator_traits::pointer			pointer;
		typedef typename iterator_traits::difference_type	difference_type;



		VectorIterator() : p(nullptr) { }

		VectorIterator(pointer _p) : p(_p) { }

		VectorIterator(const VectorIterator &it) : p(it.p) { }

		~VectorIterator() { }


			// INPUT_ITERATOR
		
		bool		operator != (VectorIterator &rv) { return this->p != rv.p; }
		reference	operator * () { return *this->p; }
		pointer		operator -> () { return this->p; }


			// BIDIRECTIONAL_ITERATOR

		VectorIterator	&operator ++ () {
			++this->p;
			return *this;
		}

		VectorIterator	operator ++ (int) {
			VectorIterator	dst = *this;
			++this->p;
			return dst;
		}


			//	RANDOM_ACCESS_ITERATOR

		VectorIterator	&operator -- () {
			--this->p;
			return *this;
		}

		VectorIterator	operator -- (int) {
			VectorIterator	dst = *this;
			--this->p;
			return dst;
		}

		VectorIterator	&operator += (difference_type n) {
			this->p += n;
			return *this;
		}

		VectorIterator	operator + (difference_type n) {
			VectorIterator	dst = *this;
			dst += n;
			return dst;
		}

		difference_type	operator + (const VectorIterator &other) { return this->p + other.p; }

		VectorIterator	&operator -= (difference_type n) {
			this->p -= n;
			return *this;
		}

		VectorIterator	operator - (difference_type n) {
			VectorIterator	dst = *this;
			dst -= n;
			return dst;
		}

		difference_type	operator - (const VectorIterator &other) { return this->p - other.p; }

		reference		operator [] (const size_t i) { return *(this->p + i); }
		bool			operator < (const VectorIterator &other) { return this->p < other.p; }
		bool			operator > (const VectorIterator &other) { return this->p > other.p; }
		bool			operator >= (const VectorIterator &other) { return this->p >= other.p; }
		bool			operator <= (const VectorIterator &other) { return this->p <= other.p; }

		const VectorIterator	&base() const { return p; }

		friend std::ostream	&operator << (std::ostream &out, const VectorIterator &it) {
			out << it.p;
			return (out);
		}

	// private :
		pointer		p;
		
} ;



template <typename T, typename Allocator = std::allocator<T> >
class Vector {

	public :
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef VectorIterator<value_type>				iterator;
		typedef VectorIterator<const value_type>		const_iterator;
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef std::reverse_iterator<const_iterator>	const_revese_iterator;

	private :
		size_type		_size;
		size_type		_capacity;
		pointer			_vec;
		allocator_type	_alloc;

	public :

			//	MEMBER FUNCIONS

		Vector() :
		_size(0), _capacity(0), _vec(nullptr), _alloc(allocator_type()) { }

		explicit Vector(const allocator_type alloc) :
		_size(0), _capacity(0), _vec(nullptr), _alloc(alloc) { } 

		explicit Vector(size_type count, const_reference value = T(), allocator_type alloc = allocator_type()) :
		_size(count), _capacity(count), _alloc(alloc) {
			this->_vec = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_vec + i, value);
		}

		Vector(const Vector &other) :
		_size(other._size), _capacity(other._capacity), _alloc(other._alloc) {
			this->_vec = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(&this->_vec[i], other[i]);
		}

		~Vector() {
			if (this->_capacity != 0) {
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_vec[i]);
				this->_alloc.deallocate(this->_vec, this->_capacity);
			}
		}

		Vector	&operator = (const Vector &other) {
			for (size_type i = 0; i < other._size; i++) {
				// push_back
			}
		}
			//	ELEMENT ACCESS

		reference		at(size_type pos) {
			if (pos >= this->_size)
				throw std::out_of_range::exception();
			return this->_vec[pos];
		}

		const_reference	at(size_type pos) const {
			if (pos >= this->_size)
				throw std::out_of_range::exception();
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

		const_revese_iterator	rbegin() const { return const_revese_iterator(this->end()); }

		reverse_iterator		rend() { return reverse_iterator(this->begin()); }

		const_revese_iterator	rend() const { return reverse_iterator(this->begin()); }

			//	CAPACITY

		bool		empty() const { return static_cast<bool>(this->_size); }

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
			difference_type	diff = std::distance(first, last);

			__insert(first, last, this->end());
			for (iterator it = this->end() - diff - 1; it < this->end(); it++) {
				this->_alloc.destroy(it.p);
			}
			this->_size -= diff;
			return last;
		}

		void		push_back(const_reference value) {
			insert(this->end(), value);
		}

		void		pop_back() {
			this->_alloc.destroy(this->back().p);
		}

		void		swap(Vector &other) {
			std::swap(this->_capacity, other._capacity);
			std::swap(this->_size, other._size);
			std::swap(this->_vec, other._vec);
		}

	private :

		iterator	__reverse_insert(iterator dst, iterator src_begin, iterator src_end) {
			while (src_begin >= src_end) {
				this->_alloc.construct(dst.p, *src_begin.p);
				--src_begin;
				--dst;
			}
			return dst;
		}

		iterator	__insert(iterator dst, iterator src_begin, iterator src_end) {
			while (src_begin <= src_end) {
				this->_alloc.construct(dst.p, *src_begin.p);
				++src_begin;
				++dst;
			}
			return dst;
		}

		void	__hidden_insert(iterator pos, size_type count, const_reference value, true_type) {
			difference_type	diff = std::distance(this->begin(), pos);

			this->reserve(this->_capacity << 1 > this->_size + count ? this->_capacity << 1 : this->_size + count);
			__reverse_insert(this->begin() + this->_size + count - 1, this->begin() + this->_size  - 1, this->begin() + diff);
			for (iterator it = this->begin() + diff; it < this->begin() + diff + count; it++) {
				this->_alloc.construct(it.p, value);
			}
			this->_size += count;
		}

		template <typename InputIt>
		void	__hidden_insert(iterator pos, InputIt first, InputIt last, false_type) {
			difference_type count = std::distance(first, last);
			difference_type	diff = std::distance(this->begin(), pos);

			this->reserve(this->_capacity << 1 > this->_size + count ? this->_capacity << 1 : this->_size + count);
			__reverse_insert(this->begin() + this->_size + count - 1, this->begin() + this->_size - 1, this->begin() + diff);
			for (iterator it = this->begin() + diff; first < last; it++) {
				this->_alloc.construct(it.p, *first.base());
				++first;
			}
			this->_size += count;
		}


} ;


}

#endif
