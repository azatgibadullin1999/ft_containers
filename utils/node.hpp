/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:06:57 by root              #+#    #+#             */
/*   Updated: 2021/12/29 18:47:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP


namespace ft {


template <typename T>
struct binary_node {

	typedef T	value_type;

	value_type	*value;
	binary_node	*parent;
	binary_node	*right;
	binary_node	*left;

} ;


}


#endif