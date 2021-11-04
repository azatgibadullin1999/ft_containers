/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:51:27 by root              #+#    #+#             */
/*   Updated: 2021/11/03 17:43:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <vector>
# include <memory>
# include <iterator>
# include <cstddef>
# include <exception>

template <typename T>
class VectorIterator : public std::iterator<std::random_access_iterator_tag, T> {

	public :
			// TYPDEF

		typedef T				value_type;
		typedef T&				reference;
		typedef T*				pointer;
		typedef std::ptrdiff_t	difference_type;

		
			// INPUT_ITERATOR
		
		bool		operator != (reference rv) { return this->p != rv->p; }
		reference	operator * () { return *this->p; }
		pointer		operator -> () { return this->p; }

			// BIDIRECTIONAL_ITERATOR

		reference	operator ++ () {
			++this->p;
			return *this;
		}

		value_type	operator ++ (int) {
			VectorIterator	dst = *this;
			++this->p;
			return dst;
		}

			//	RANDOM_ACCESS_ITERATOR

		reference	operator -- () {
			--this->p;
			return *this;
		}

		value_type	operator -- (int) {
			VectorIterator	dst = this;
			--this->p;
			return dst;
		}

		reference	operator += (const long n) {
			this->p += n;
			return *this;
		}

		value_type	operator + (const long n) {
			VectorIterator	dst = *this;
			dst += n;
			return dst;
		}

		reference	operator -= (const long n) {
			this->p -= n;
			return *this;
		}

		value_type	operator - (const long n) {
			VectorIterator	dst = *this;
			dst -= n;
			return dst;
		}

		reference		operator [] (const size_t i) { return *(this->p + i); }
		bool			operator < (reference other) { return this->p < this->p; }
		bool			operator > (reference other) { return this->p > this->p; }
		bool			operator >= (reference other) { return this->p >= this->p; }
		bool			operator <= (reference other) { return this->p <= this->p; }

	private :
		pointer		p;
		
} ;



template <typename T, class Allocator = std::allocator<T>>
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


			//	MEMBER FUNCIONS

		Vector() : _size(0), _capacity(0), _vec(nullptr), _alloc(allocator_type()) { }

		explicit Vector(const allocator_type alloc) _size(0), _capacity(0), _vec(nullptr), _alloc(alloc) { } 

		explicit Vector(size_type count, const_reference value = T(), allocator_type _alloc = allocator_type()) : _size(count), _capacity(count << 1) {
			if (count != 0) {
			this->_vec = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++) {
				this->_alloc.construct(this->_vec + i, T);
			}
		}

		Vector(const Vector &other) : _alloc(other._alloc), _size(other._size), _capacity(other._capacity) {
			this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++) {
				this->_alloc.construct(this->_vec + i, other[i]);
			}
		}

		~Vector() {
			for (size_type i = 0; i < this->_capacity; i++) {
				this->_alloc.destroy(this->_vec + i);
			}
			this->_alloc.deallocate(this->_arr, this->_capacity);
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
			return this->_vec[i];
		}

		const_reference	at(size_type pos) const {
			if (pos >= this->_size)
				throw std::out_of_range::exception();
			return this->_vec[i];
		}

		reference		operator [] (size_type pos) { return this->_vec[i]; }

		const_reference	operator [] (size_type pos) const { return this->_vec[i]; }

		reference		front() { return this->_vec[0]; }

		const_reference	front() const { return this->_vec[0]; }

		reference		back() { return this->_vec[this->_size - 1]; }

		const_reference	back() const { return this->_vec[this->_size - 1]; }

		pointer			data() { return (this->_vec); }

		const_pointer	data() const { return (this->_vec); }

			//	ITERATORS

		iterator				begin() { return iterator(this->_vec); }

		const_iterator			begin() const { return const_iterator(this->_vec); }

		iterator				end() { return iterator(&this->_vec[this->_size - 1]); }

		const_iterator			end() const { return const_iterator(&this->_vec[this->_size - 1]); }

		reverse_iterator		rbegin() { return reverse_iterator(this->end()); }

		const_revese_iterator	rbegin() const { return const_revese_iterator(this->end()); }

		reverse_iterator		rend() { return reverse_iterator(this->begin()); }

		const_revese_iterator	rend() const { return reverse_iterator(this->begin()); }

			//	CAPACITY

		bool		empty() const { return static_cast<bool>(this->_size); }

		size_type	size() const { return this->_size; }

		// size_type	max_size() const { return }

		// void		reserve(size_type new_cap) { }

		size_type	capacity() const { return this->_capacity; }

			//	MODIFIERS

		void	clear() {
			for (size_type i = 0; i < this->_size; i++) {
				this->_alloc.destroy(this->_vec + i);
			}
		}

		iterator	insert(iterator pos, const_referece value) {
			--pos = 
		}

		void		insert(iterator pos, size_type count, const_referece value) {

		}


	private :
		size_type		_size;
		size_type		_capacity;
		pointer			_vec;
		allocator_type	_alloc;
} ;

#endif