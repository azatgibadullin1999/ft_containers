/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:36:15 by root              #+#    #+#             */
/*   Updated: 2021/12/28 16:22:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP


namespace ft {


template <typename InputIt1, typename InputIt2>
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
	for (; first1 != last1; first1++, first2++) {
		if (!(*first1 == *first2))
			return false;
	}
	return true;
}

template <typename InputIt1, typename InputIt2, typename BinaryPredicate>
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
	for(; first1 != last1; first1++, first2++) {
		if (!p(*first1, first2))
			return false;
	}
	return true;
}

	
}


#endif