/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:53:58 by root              #+#    #+#             */
/*   Updated: 2021/12/21 17:51:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <iterator>
# include "utils.hpp"
# include "iterators.hpp"

namespace ft {


template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<std::pair<const Key, T> >
		>
class map {

	public :

		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const Key, T>					value_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef Compare									key_compare;
		typedef Allocator								allocator_type;
		typedef typename Allocator::reference			reference;
		typedef typename Allocator::const_reference		const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator

	private :

		typedef ft::Node<value_type>								_node;
		typedef typename Allocator::template rebind<_node>::other	_node_allocator_type;
		typedef	typename _node_allocator_type::pointer				_node_pointer;
		typedef	typename _node_allocator_type::const_pointer		_node_const_pointer;
		typedef typename _node_allocator_type::reference			_node_reference;
		typedef typename _node_allocator_type::const_reference		_node_const_reference;

		size_type				_size;
		_node_pointer			_node_begin;
		_node_allocator_type	_node_alloc;

	public :
		//	Member class

		Compare					_comp;

		//	Member fuctions

		map() :
		_comp(), _node_alloc(), _node_begin(nullptr) { }

		explicit map(const Compare &comp,
					const Allocator &alloc = Allocator()) :
					_comp(comp), _node_alloc(alloc), _node_begin(nullptr) { }

		template <typename InputIt>
		map(InputIt first,
			InputIt last,
			const Compare &comp = Compare(),
			const Allocator &alloc = Allocator()) :
			_comp(comp), _node_alloc(alloc) { }

		map(const map &other) :
		_comp(other._comp), _node_alloc(other._node_alloc) {
			__post_iter(other._node_begin, __copy_constructor());
		}

		~map() {
			__prev_iter(this->_node_begin, __destroy());
		}

		map		&operator = (const map &other) {
			_node_pointer p = this->_node_begin;
		}

		allocator_type	get_allocator() const { }

		//	Element access

		// -

		//	Capacity

		bool		empty() const { return !this->_size; }

		size_type	size() const { return this->_size; }

		size_type	max_size() const { }

		//	Modifiers

		void		clear() {
			__prev_iter(this->_node_begin, __destroy);
		}

		ft::pair<iterator, bool>	insert(const_reference value) {

		}

		iterator					insert(iterator hint, const_reference value) {

		}

		template <typename InputIt>
		void	insert(InputIt first, InputIt last) {

		}

		
	private :

		void	__destroy(_node_pointer node) {
			this->_node_alloc.destroy(node);
			this->_node_alloc.deallocate(node, 1);
		}

		void	__copy_constructor(_node_pointer other_node) {

		}

		void	__prev_iter(_node_pointer node, void (*func)(_node_pointer)) {
			if (node == nullptr)
				return ;
			__delete_all_elemets(node->left);
			__delete_all_elemets(node->right);
			func(node);
		}
		
		void	__post_iter(_node_pointer node, void (*func)(_node_pointer)) {
			if (node == nullptr)
				return ;
			func(node);
			__delete_all_elemets(node->left);
			__delete_all_elemets(node->right);
		}

		void	__balancing_tree() {
				
		}


} ;


}

#endif