/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:27:45 by root              #+#    #+#             */
/*   Updated: 2021/12/28 16:22:41 by root             ###   ########.fr       */
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