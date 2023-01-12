/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unordered_map.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 04:49:57 by larlena           #+#    #+#             */
/*   Updated: 2023/01/12 08:30:43 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNORDERED_MAP_HPP_
# define UNORDERED_MAP_HPP_


# include <initializer_list>
# include <functional>
# include <memory>
# include "vector.hpp"
# include "utils.hpp"


namespace ft {


	namespace {
		enum node_state {
			FREE,
			IN_USE,
			ERASED
		} ;
		template <typename T>
		struct node {
			T		value;
			node_state	state;
		} ;
	}


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
	private :
		typedef node<value_type>			node_type;

		std::size_t	size_;
		std::size_t	capacity_;
		hasher		hasher_;
		ft::vector<node_type, allocator_type>	table_;
	public :
			//	Constructors
		unordered_map() : size_(), capacity_() { }

		explicit unordered_map(const allocator_type &alloc) : table_(alloc) { }

		template <typename InuptIt>
		unordered_map(	InuptIt first, InuptIt last,
				const hasher &hash = hasher(),
				const key_equal &equal = key_equal(),
				const allocator_type &alloc = allocator_type()) { }
		
		unordered_map(const unordered_map &other) { }

		unordered_map(const unordered_map &other, const allocator_type &alloc) { }

		unordered_map(const unordered_map &&other) { }

		unordered_map(const unordered_map &&other, const allocator_type &alloc) { }

		unordered_map(	std::initializer_list<value_type> init,
				const hasher &hash = hasher(),
				const key_equal &equal = key_equal(),
				const allocator_type &alloc = allocator_type()) { }

		~unordered_map() { }

			//	Operator =

		unordered_map	&operator = (const unordered_map &other) { }

		unordered_map	&operator = (const unordered_map &&other) { }

		unordered_map	&operator = (std::initializer_list<value_type> ilist) { }

		allocator_type	get_allocator() const noexcept { }

} ;


}


#endif