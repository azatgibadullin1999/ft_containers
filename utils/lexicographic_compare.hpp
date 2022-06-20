/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographic_compare.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:36:54 by root              #+#    #+#             */
/*   Updated: 2022/06/20 13:16:14 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP


namespace ft {


template <typename InputIt1, typename InputIt2>
bool	lexicographic_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
	for (; (first1 != last1) && (first2 != last2); first1++, first2++) {
		if (*first1 < *first2)
			return true;
		if (*first2 < *first1)
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}								

template <typename InputIt1, typename InputIt2, typename Compare>
bool	lexicographic_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
	for (; (first1 != last1) && (first2 != last2); first1++, first2++) {
		if (comp(*first1, *first2))
			return true;
		if (comp(*first2, *first1))
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}


}


#endif