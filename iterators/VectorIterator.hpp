/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:08:28 by root              #+#    #+#             */
/*   Updated: 2022/06/28 19:55:37 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR
# define VECTOR_ITERATOR

# include <iterator>
# include "../utils.hpp"

namespace ft {


template <typename Iter>
class vector_iterator : public std::iterator<std::random_access_iterator_tag, Iter> {

	private :

		typedef ft::iterator_traits<Iter>	iterator_traits;

	public :

			// TYPDEF

		typedef typename iterator_traits::iterator_category	iterator_category;
		typedef typename iterator_traits::value_type		value_type;
		typedef typename iterator_traits::reference		reference;
		typedef typename iterator_traits::pointer		pointer;
		typedef typename iterator_traits::difference_type	difference_type;

	private :

		Iter	p;

	public :

		vector_iterator() : p(NULL) { }

		vector_iterator(const Iter _p) : p(_p) { }

		template <typename _Iter>
		vector_iterator(const vector_iterator<_Iter> it) : p(it.base()) { }

		~vector_iterator() { }

			// INPUT_ITERATOR

		vector_iterator	&operator = (const vector_iterator& other) {
			this->p = other.p;
			return *this;
		}

		reference	operator * () { return *this->p; }
		pointer		operator -> () { return this->p; }


			// BIDIRECTIONAL_ITERATOR

		vector_iterator	&operator ++ () {
			++this->p;
			return *this;
		}

		vector_iterator	operator ++ (int) {
			vector_iterator	dst = *this;
			++this->p;
			return dst;
		}


			//	RANDOM_ACCESS_ITERATOR

		vector_iterator	&operator -- () {
			--this->p;
			return *this;
		}

		vector_iterator	operator -- (int) {
			vector_iterator	dst = *this;
			--this->p;
			return dst;
		}

		vector_iterator	&operator += (difference_type n) {
			this->p += n;
			return *this;
		}

		vector_iterator	operator + (difference_type n) {
			vector_iterator	dst = *this;
			dst += n;
			return dst;
		}

		difference_type	operator + (const vector_iterator &other) { return this->p + other.p; }

		vector_iterator	&operator -= (difference_type n) {
			this->p -= n;
			return *this;
		}

		vector_iterator	operator - (difference_type n) {
			vector_iterator	dst = *this;
			dst -= n;
			return dst;
		}

		difference_type	operator - (const vector_iterator &other) { return this->p - other.p; }

		reference	operator [] (const size_t i) const { return *(this->p + i); }

		pointer const	&base() const { return p; }


} ;

template <typename T_L, typename T_R>
bool	operator == (const ft::vector_iterator<T_L> lhs, ft::vector_iterator<T_R> rhs) {
	return lhs.base() == rhs.base();
}

template <typename T_L, typename T_R>
bool	operator != (const ft::vector_iterator<T_L> lhs, ft::vector_iterator<T_R> rhs) {
	return !(lhs == rhs);
}

template <typename T_L, typename T_R>
bool	operator < (const ft::vector_iterator<T_L> lhs, ft::vector_iterator<T_R> rhs) {
	return lhs.base() < rhs.base();
}

template <typename T_L, typename T_R>
bool	operator > (const ft::vector_iterator<T_L> lhs, ft::vector_iterator<T_R> rhs) {
	return rhs < lhs;
}

template <typename T_L, typename T_R>
bool	operator <= (const ft::vector_iterator<T_L> lhs, ft::vector_iterator<T_R> rhs) {
	return !(lhs > rhs);
}

template <typename T_L, typename T_R>
bool	operator >= (const ft::vector_iterator<T_L> lhs, ft::vector_iterator<T_R> rhs) {
	return !(lhs < rhs);
}

template <typename Iter>
typename ft::vector_iterator<Iter>
operator + (typename ft::vector_iterator<Iter>::difference_type lhs,
			ft::vector_iterator<Iter> rhs) {
	return rhs + lhs;
}

template <typename Iter>
typename ft::iterator_traits<Iter>::difference_type
operator - (ft::vector_iterator<Iter> lhs,
			ft::vector_iterator<Iter> rhs) {
	return lhs.base() - rhs.base();
} 

template <typename T_L, typename T_R>
typename ft::iterator_traits<T_L>::difference_type
operator - (ft::vector_iterator<T_L> lhs,
			ft::vector_iterator<T_R> rhs) {
	return lhs.base() - rhs.base();
}


}


#endif