/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:53:58 by root              #+#    #+#             */
/*   Updated: 2022/02/22 15:29:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <limits>
# include "iterators.hpp"
# include "utils.hpp"

# include <iostream>
# include <stdlib.h>

namespace ft {


template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator< ft::pair<const Key, T> >
		>
class map {

	public :

		// Public typedefs

		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair<const Key, T>							value_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef Compare											key_compare;
		typedef Allocator										allocator_type;
		typedef typename Allocator::reference					reference;
		typedef typename Allocator::const_reference				const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef binary_tree_iterator<value_type>				iterator;
		typedef binary_tree_const_iterator<value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

	private :

		//	Private Node's typedefs

		typedef binary_node<value_type>								_node;
		typedef typename Allocator::template rebind<_node>::other	_node_allocator_type;
		typedef typename _node_allocator_type::pointer				_node_pointer;
		typedef typename _node_allocator_type::reference			_node_reference;

		//	Private variables

		size_type				_size;
		key_compare				_comp;
		allocator_type			_alloc;

		_node_allocator_type	_node_alloc;
		_node_pointer			_nil;
		_node_pointer			_root;
		_node_pointer			_last_left;
		_node_pointer			_last_right;

	public :

		//	Member class

		Compare					value_compare;

		//	Member fuctions

		map() :
			_size(0),
			_comp(),
			_node_alloc(),
			_nil(_node_alloc.allocate(1)),
			_root(_nil),
			_last_left(_nil),
			_last_right(_nil) {
				__node_init(_nil);
			}

		explicit map(const Compare &comp,
					const Allocator &alloc = Allocator()) :
						_size(0),
						_comp(comp),
						_node_alloc(alloc),
						_nil(_node_alloc.allocate(1)),
						_root(_nil),
						_last_left(_nil),
						_last_right(_nil) {
							__node_init(_nil);
						}

		template <typename InputIt>
		map(InputIt first,
			InputIt last,
			const Compare &comp = Compare(),
			const Allocator &alloc = Allocator()) :
				_size(0),
				_comp(comp),
				_node_alloc(alloc),
				_nil(_node_alloc.allocate(1)),
				_root(_nil),
				_last_left(_nil),
				_last_right(_nil) {
					__node_init(_nil);
					insert(first, last);
				}

		map(const map &other) :
			_size(0),
			_comp(other._comp),
			_node_alloc(other._node_alloc),
			_nil(_node_alloc.allocate(1)),
			_root(_nil),
			_last_left(_nil),
			_last_right(_nil) {
				__node_init(_nil);
				insert(other.begin(), other.end());
			}

		~map() {
			if (!empty())
				__prev_iter(_root, &map::__node_destroy);
			__list_destroy(_nil);
		}

		map		&operator = (const map &other) {
			if (this == &other)
				return *this;
			clear();
			insert(other.begin(), other.end());
			return *this;
		}

		allocator_type	get_allocator() const {
			return _alloc;
		}

		//	Element access

		mapped_type			&at(const key_type &key) {
			_node_pointer dst = __find(_root, key);
			if (dst == _nil)
				throw std::out_of_range("out of range");
			else
				return dst->value->second;
		}

		const mapped_type	&at(const key_type &key) const {
			_node_pointer dst = __find(_root, key);
			if (dst == _nil)
				throw std::out_of_range("out of range");
			else
				return dst->value->second;
		}

		mapped_type		&operator [] (const key_type &key) {

			return insert(ft::make_pair(key, mapped_type())).first._M_node->value->second;
		}

		//	Iterators

		iterator				begin() {
			return iterator(_last_left);
		}
		
		const_iterator			begin() const {
			return const_iterator(_last_left);
		}

		iterator				end() {
			return iterator(_nil);
		}

		const_iterator			end() const {
			return const_iterator(_nil);
		}

		reverse_iterator		rbegin() {
			return reverse_iterator(end());
		}

		const_reverse_iterator	rbegin() const {
			return const_reverse_iterator(end());
		}

		reverse_iterator		rend() {
			return reverse_iterator(begin());
		}

		const_reverse_iterator	rend() const {
			return const_reverse_iterator(begin());
		}

		//	Capacity

		bool					empty() const { return !_size; }

		size_type				size() const { return _size; }

		size_type				max_size() const {
			return std::min((size_type) std::numeric_limits<difference_type>::max(),
					std::numeric_limits<size_type>::max() / sizeof(_node) + sizeof(_node_pointer));
		}

		//	Modifiers

		void		clear() {
			__prev_iter(_root, &map::__node_destroy);
			__node_init(_nil);
			_root = _nil;
			_last_left = _nil;
			_last_right = _nil;
			_size = 0;
		}

		ft::pair<iterator, bool>	insert(const_reference value) {
			_node_pointer new_node = __node_create(value);
			_node_pointer returned_node = __insert(new_node);

			if (returned_node == new_node) {
				++_size;
				return ft::make_pair(iterator(new_node), true);
			}
			else {
				__node_destroy(new_node);
				return ft::make_pair(iterator(returned_node), false);
			}
		}

		iterator					insert(iterator hint, const_reference value) {
			(void)hint;
			return insert(value).first;
		}

		template <typename InputIt>
		void						insert(InputIt first, InputIt last) {
			while (first != last)
				insert(*first++);
		}

		void		erase(iterator pos) {
			__erase(pos._M_node);
			__node_destroy(pos._M_node);
			--_size;
		}

		void		erase(iterator first, iterator last) {
			while (first != last)
				erase(first++);
		}

		size_type	erase(const key_type &key) {
			_node_pointer	elem = __find(_root, key);

			if (elem == _nil)
				return 0;
			erase(elem);
			return 1;
		}

		void	swap(map &other) {
			(void)other;
		}

		//	Lookup

		size_type		count(const key_type &key) const {
			_node_pointer	node = __find(_root, key);

			return node != _nil;
		}

		iterator		find(const key_type &key) {
			return iterator(__find(_root, key));		
		}

		const_iterator	find(const key_type &key) const {
			return const_iterator(__find(_root, key));
		}

		iterator		upper_bound(const key_type &key) {
			return iterator(__upper_bound(key));
		}

		const_iterator	upper_bound(const key_type &key) const {
			return const_iterator(__upper_bound(key));
		}

		iterator		lower_bound(const key_type &key) {
			return iterator(__lower_bound(key));
		}

		const_iterator	lower_bound(const key_type &key) const {
			return const_iterator(__lower_bound(key));
		}

		ft::pair<iterator, iterator>				equal_range(const key_type &key) {
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		ft::pair<const_iterator, const_iterator>	equal_range(const key_type &key) const {
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

	private :

		_node_pointer	__lower_bound(const key_type &key) const {
			_node_pointer	dst = _last_left;

			while (dst != _nil && _comp(dst->value->first, key))
				dst = __tree_increment(dst);

			return dst;
		}

		_node_pointer	__upper_bound(const key_type &key) const {
			_node_pointer	dst = _last_left;

			while (dst != _nil && _comp(key, dst->value->first))
				dst = __tree_increment(dst);

			return dst;
		}

		void		__erase(_node_pointer node) {
			__tree_rebalance(node);
		}

		void		__tree_rebalance(_node_pointer node) {
			(void)node;
		}

		_node_pointer	__insert(_node_pointer new_node) {
			if (empty()) {
				_root = __node_init(new_node, _nil, new_node->left);
				_last_left = _root;
				_last_right = _root;
				_nil->parent = _last_right;
				_nil->left = _last_right;
				_nil->right = _last_left;
				return _root;
			}
			else {
				_node_pointer	parent = __iter_comp(_root, new_node->value->first);
				if (_comp(parent->value->first, new_node->value->first)) {
					if (parent == _last_right) {
						_last_right = new_node;
						_nil->parent = _last_right;
						_nil->left = _last_right;
					}
					return __node_init(new_node, parent, parent->right);
				}
				else if (_comp(new_node->value->first, parent->value->first)) {
					if (parent == _last_left) {
						_last_left = new_node;
						_nil->right = _last_left;
					}
					return __node_init(new_node, parent, parent->left);
				}
				return parent;
			}
		}

		_node_pointer	__find(_node_pointer p, const key_type &key) const {
			if (p == _nil)
				return p;
			else if (_comp(key, p->value->first))
				return __find(p->left, key);
			else if (_comp(p->value->first, key))
				return __find(p->right, key);
			return p;
		}

		_node_pointer	__iter_comp(_node_pointer p, const key_type &key) {
			if (_comp(key, p->value->first) && p->left != _nil)
				return __iter_comp(p->left, key);
			else if (_comp(p->value->first, key) && p->right != _nil)
				return __iter_comp(p->right, key);
			return p;
		}

		void			__prev_iter(_node_pointer node, void (map::*func)(_node_pointer)) {
			if (node == _nil)
				return ;
			__prev_iter(node->left, func);
			__prev_iter(node->right, func);
			(this->*func)(node);
		}
		
		void			__post_iter(_node_pointer node, void (map::*func)(_node_pointer)) {
			if (node == _nil)
				return ;
			(this->*func)(node);
			__post_iter(node->left, func);
			__post_iter(node->right, func);
		}

		_node_pointer	__node_init(_node_pointer nil) {
			nil->parent = _nil;
			nil->value = nullptr;
			nil->left = _nil;
			nil->right = _nil;
			return _nil;
		}

		_node_pointer	__node_init(_node_pointer new_node, _node_pointer parent, _node_pointer &parent_direction) {
			parent_direction = new_node;
			new_node->parent = parent;
			new_node->left = _nil;
			new_node->right = _nil;
			return new_node;
		}

		_node_pointer	__node_create(const_reference value) {
			_node_pointer	new_node = _node_alloc.allocate(1);
			_node_alloc.construct(new_node, _node());
			new_node->value = _alloc.allocate(1);
			_alloc.construct(new_node->value, value);
			return new_node;
		}

		void			__node_destroy(_node_pointer elem) {
			__value_destroy(elem);
			__list_destroy(elem);
		}

		void			__list_destroy(_node_pointer elem) {
			_node_alloc.destroy(elem);
			_node_alloc.deallocate(elem, 1);
		}

		void			__value_destroy(_node_pointer elem) {
			_alloc.destroy(elem->value);
			_alloc.deallocate(elem->value, 1);
		}

		_node_pointer	&__get_parent_direction(_node_pointer node) {
			if (node->parent->right == node)
				return node->parent->right;
			else
				return node->parent->left;
		}

} ;


}


#endif