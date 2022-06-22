/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:57:07 by root              #+#    #+#             */
/*   Updated: 2022/06/20 13:16:29 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP


namespace ft {


template <typename T1, typename T2>
struct pair {
	
		typedef T1		first_type;
		typedef T2		second_type;

		first_type		first;
		second_type		second;


		pair() :
		first(), second() { }

		pair(first_type _first, second_type _second) :
		first(_first), second(_second) { }

		template <typename U1, typename U2>
		pair(const pair<U1, U2>& _p) :
		first(_p.first), second(_p.second) { }

		pair(const pair &other) :
		first(other.first), second(other.second) { }


		pair	&operator = (const pair& other) {
			this->first = other.first;
			this->second = other.second;
			return *this;
		}

} ;

template<typename T1, typename T2>
bool	operator == (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

template<typename T1, typename T2>
bool	operator != (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return !(lhs == rhs);
}

template<typename T1, typename T2>
bool	operator < (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return lhs.first < rhs.first || ((lhs.first == rhs.first) && lhs.second < rhs.second);
}

template<typename T1, typename T2>
bool	operator > (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return rhs < lhs;
}

template<typename T1, typename T2>
bool	operator <= (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return !(lhs > rhs);
}

template<typename T1, typename T2>
bool	operator >= (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return !(lhs < rhs);
}


}


#endif
