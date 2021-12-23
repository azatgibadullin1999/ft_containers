/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:22:18 by root              #+#    #+#             */
/*   Updated: 2021/12/14 14:59:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {


template <class Iter>
struct iterator_traits {
	typedef typename Iter::iterator_category	iterator_category;
	typedef typename Iter::value_type			value_type;
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::reference			reference;
	typedef typename Iter::pointer				pointer;
} ;

template <typename T>
struct iterator_traits<T*> {
	typedef typename std::random_access_iterator_tag	iterator_category;
	typedef T											value_type;
	typedef typename std::ptrdiff_t						difference_type;
	typedef T&											reference;
	typedef T*											pointer;							
} ;

template <typename T>
struct iterator_traits<const T*> {
	typedef typename std::random_access_iterator_tag	iterator_category;
	typedef T											value_type;
	typedef typename std::ptrdiff_t						difference_type;
	typedef const T&									reference;
	typedef const T*									pointer;							
} ;


}

#endif
