/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:21:24 by root              #+#    #+#             */
/*   Updated: 2022/06/20 13:16:05 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP


namespace ft {


struct true_type { } ;
struct false_type { } ;


template <typename T>
	struct is_integral_res;

template <>
	struct is_integral_res <true_type> {
		static const bool value =	1;
		typedef true_type		type;
} ;

template <>
	struct is_integral_res <false_type> {
		static const bool value = 	0;
		typedef false_type		type;
} ;


template <typename T>
	struct is_integral_type : public is_integral_res<false_type> { };

 
template <>
	struct is_integral_type<bool> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<char> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<signed char> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<short int> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<int> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<long int> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<long long int> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<unsigned char> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<unsigned short int> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<unsigned int> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<unsigned long int> : public is_integral_res<true_type> { };

template <>
	struct is_integral_type<unsigned long long int> : public is_integral_res<true_type> { };



template <typename T>
	struct is_integral : public is_integral_type<T> { };


}


#endif
