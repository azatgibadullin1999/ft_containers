/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:27:45 by root              #+#    #+#             */
/*   Updated: 2022/06/20 13:15:54 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP


namespace ft {


template <bool, typename T = void>
	struct enable_if { } ;

template <typename T>
	struct enable_if <true, T> {
		typedef T		type;
	} ;


}


#endif