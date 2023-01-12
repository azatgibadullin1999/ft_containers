/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unordered_map.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 04:49:57 by larlena           #+#    #+#             */
/*   Updated: 2023/01/12 05:42:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNORDERED_MAP_HPP_
# define UNORDERED_MAP_HPP_


# include <functional>
# include <memory>
# include "utils.hpp"


namespace ft {


template <	typename Key,
		typename T,
		typename Hash = std::hash<Key>,
		typename KeyEqueal = std::equal_to<Key>,
		typename Allocator = std::allocator<ft::pair<Key, T>>	>
class unordered_map {
	public :
		typedef Key					key_type;
		typedef T					mapped_type;
		typedef ft::pair<const Key, T>			value_type;
		typedef std::size_t				size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef Hash					hasher;
		typedef KeyEqueal				key_equal;
		typedef Allocator				allocator_type;
		typedef value_type &				reference;
		typedef const value_type &			const_reference;
		typedef typename Allocator::pointer		pointer;
		typedef typename Allocator::const_pointer	const_pointer;

} ;


}


#endif