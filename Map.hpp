/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:53:58 by root              #+#    #+#             */
/*   Updated: 2021/12/03 16:45:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>

namespace ft {


template <typename T>
class Node {

	T		value;
	Node	*right;
	Node	*left;

} ;




template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<std::pair<const Key, T> >
		>
class Map {

	public :

		typedef Key													key_type;
		typedef T													mapped_type;
		typedef std::pair<cont Key, T>								value_type;
		typedef size_t												size_type;
		typedef ptrdiff_t											difference_type;
		typedef Compare												key_compare;
		typedef Allocator											allocator_type;
		typedef Allocator::template rebind<Node<value_type>>::other	node_allocator;
		typedef value_type&											reference;
		typedef const value_type&									const_reference;
		typedef Allocator::pointer									pointer;
		typedef Allocator::const_pointer							const_pointer;
		typedef 

	private :

} ;


}

#endif