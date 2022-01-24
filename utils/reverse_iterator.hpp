/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:24:07 by root              #+#    #+#             */
/*   Updated: 2021/12/28 16:23:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP


namespace ft {


template <class Iterator>
class reverse_iterator : public std::iterator <
				typename iterator_traits<Iterator>::iterator_category,
				typename iterator_traits<Iterator>::value_type,
				typename iterator_traits<Iterator>::difference_type,
				typename iterator_traits<Iterator>::pointer,	
				typename iterator_traits<Iterator>::reference >
{
	
	protected :

		typedef ft::iterator_traits<Iterator>			iterator_traits;

	public :

			// TYPDEF

		typedef Iterator									iterator_type;
		typedef typename iterator_traits::iterator_category	iterator_category;
		typedef	typename iterator_traits::value_type		value_type;
		typedef typename iterator_traits::reference			reference;
		typedef typename iterator_traits::pointer			pointer;
		typedef	typename iterator_traits::difference_type	difference_type;

	protected :

		iterator_type	_iter;

	public :

		reverse_iterator() : _iter(nullptr) { }

		explicit reverse_iterator(iterator_type other) : _iter(other) { }

		template <class InputIt>
		reverse_iterator(const reverse_iterator<InputIt>& other) : _iter(other.base()) { }

		template <class InputIt>
		reverse_iterator	&operator = (const reverse_iterator<InputIt>& other) {
			this->_iter = other.base();
			return *this;
		}

		iterator_type	base() const {
			return this->_iter;
		}

		reference	operator * () const {
			iterator_type	tmp = this->_iter;
			--tmp;
			return *tmp;
		}

		pointer		operator -> () const {
			iterator_type	tmp = this->_iter;
			--tmp;
			return tmp.operator->();
		}

		reference	operator [] (difference_type n) const {
			return *(*this + n);
		}

		reverse_iterator	&operator ++ () {
			--this->_iter;
			return *this;
		}

		reverse_iterator	&operator -- () {
			++this->_iter;
			return *this;
		}

		reverse_iterator	operator ++ (int) {
			reverse_iterator	dst = *this;
			--this->_iter;
			return dst;
		}

		reverse_iterator	operator -- (int) {
			reverse_iterator	dst = *this;
			++this->_iter;
			return dst;
		}

		reverse_iterator	operator + (difference_type n) const {
			reverse_iterator	dst = *this;
			dst._iter -= n;
			return dst;
		}

		reverse_iterator	operator - (difference_type n) const {
			reverse_iterator	dst = *this;
			dst._iter += n;
			return dst;
		}

		reverse_iterator	&operator += (difference_type n) {
			this->_iter -= n;
			return *this;
		}

		reverse_iterator	&operator -= (difference_type n) {
			this->_iter += n;
			return *this;
		}

} ;


template <typename T_L, typename T_R>
bool	operator == (const ft::reverse_iterator<T_L> &lhs, const ft::reverse_iterator<T_R> &rhs) {
	return lhs.base() == rhs.base();
}

template <typename T_L, typename T_R>
bool	operator != (const ft::reverse_iterator<T_L> &lhs, const ft::reverse_iterator<T_R> &rhs) {
	return !(lhs == rhs);
}

template <typename T_L, typename T_R>
bool	operator < (const ft::reverse_iterator<T_L> &lhs, const ft::reverse_iterator<T_R> &rhs) {
	return lhs.base() > rhs.base();
}

template <typename T_L, typename T_R>
bool	operator > (const ft::reverse_iterator<T_L> &lhs, const ft::reverse_iterator<T_R> &rhs) {
	return rhs < lhs;
}

template <typename T_L, typename T_R>
bool	operator <= (const ft::reverse_iterator<T_L> &lhs, const ft::reverse_iterator<T_R> &rhs) {
	return !(lhs > rhs);
}

template <typename T_L, typename T_R>
bool	operator >= (const ft::reverse_iterator<T_L> &lhs, const ft::reverse_iterator<T_R> &rhs) {
	return !(lhs < rhs);
}

template <typename Iter>
reverse_iterator<Iter>
operator + (typename ft::reverse_iterator<Iter>::difference_type n,
			const ft::reverse_iterator<Iter> &it) {
	return it + n;
}

template <typename Iter>
typename ft::reverse_iterator<Iter>::difference_type
operator - (const ft::reverse_iterator<Iter> &lhs,
			const ft::reverse_iterator<Iter> &rhs) {
	return rhs.base() - lhs.base();
}

template <typename T_L, typename T_R>
typename ft::iterator_traits<T_L>::difference_type
operator - (ft::reverse_iterator<T_L> lhs,
			ft::reverse_iterator<T_R> rhs) {
	return rhs.base() - lhs.base();
}


}


#endif
