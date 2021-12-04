/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:24:07 by root              #+#    #+#             */
/*   Updated: 2021/12/03 15:22:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {


template <class Iter>
class reverse_iterator : public std::iterator <
				typename iterator_traits<Iter>::iterator_category,
				typename iterator_traits<Iter>::value_type,
				typename iterator_traits<Iter>::difference_type,
				typename iterator_traits<Iter>::pointer,
				typename iterator_traits<Iter>::reference >
	{
	
	private :

		typedef iterator_traits<VectorIterator>	iterator_traits;

	public :

			// TYPDEF
		typedef Iter								iterator_type;
		typedef iterator_traits::iterator_category	iterator_category;
		typedef	iterator_traits::value_type			value_type;
		typedef iterator_traits::reference			reference;
		typedef iterator_traits::pointer			pointer;
		typedef	iterator_traits::difference_type	difference_type;

	private :

		pointer		_p;

	public :

		reverse_iterator() : _p(nullptr) { }

		explicit reverse_iterator(iterator_type other) : _p(ohter._p) { }

		// template <class U>
		// reverse_iterator(const reverse_iterator<U>& other) {}

		// template <class U>
		// reverse_iterator	&operator = (const reverse_iterator<U>& other) {}

		

} ;


}

#endif
