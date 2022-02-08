/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:53:58 by root              #+#    #+#             */
/*   Updated: 2022/02/08 19:55:20 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <iterator>
# include "iterators.hpp"
# include "utils.hpp"

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

		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<const Key, T>									value_type;
		typedef std::size_t												size_type;
		typedef std::ptrdiff_t											difference_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef typename Allocator::reference							reference;
		typedef typename Allocator::const_reference						const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;
		typedef binary_tree_iterator<const key_type, mapped_type>		iterator;
		typedef binary_tree_iterator<const key_type, const mapped_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

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
		_node_pointer			_root;
		_node_pointer			_last_left;
		_node_pointer			_last_right;
		_node_pointer			_nil;

	public :

		//	Member class

		Compare					value_compare;

		//	Member fuctions

		map() :
			_size(0),
			_comp(),
			_node_alloc(),
			_root(nullptr),
			_nil(_node_alloc.allocate(1)) {
				__node_init(_nil);
			}

		explicit map(const Compare &comp,
					const Allocator &alloc = Allocator()) :
						_size(0),
						_comp(comp),
						_node_alloc(alloc),
						_root(nullptr),
						_nil(_node_alloc.allocate(1)) {
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
				_root(nullptr),
				_nil(_node_alloc.allocate(1)) {
					__node_init(_nil);
					insert(first, last);
				}

		map(const map &other) :
			_size(0),
			_comp(other._comp),
			_node_alloc(other._node_alloc),
			_root(nullptr),
			_nil(_node_alloc.allocate(1)) {
				__node_init(_nil);
				insert(other.begin(), other.end());
			}

		~map() {
			if (!empty())
				__prev_iter(_root, &map::__node_destroy);
			__node_destroy(_nil);
		}

		map		&operator = (const map &other) {
			if (this == &other)
				return *this;
			clear();
			insert(other.begin(), other.end());
		}

		allocator_type	get_allocator() const {
			return _alloc;
		}

		//	Element access

		mapped_type		&at(const key_type &key) {
			_node_pointer dst = __finde(key);
			if (_comp(dst->value->first, key) && _comp(key, dst->value->fist))
				return dst->value->second;
			else
				throw std::out_of_range("out of range");
		}

		mapped_type		&operator [] (const key_type &key) {
			_node_pointer dst = __finde(key);
			if (_comp(dst->value->first, key) && _comp(key, dst->value->fist))
				return dst->value->second;
			else
				return __insert(__node_create(ft::make_pair(key, mapped_type())))->value->second;
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

		size_type				max_size() const { }

		//	Modifiers

		void		clear() {
			__prev_iter(_root, __node_destroy());
		}

		ft::pair<iterator, bool>	insert(const_reference value) {
			_node_pointer new_node = __node_create(value);
			_node_pointer returned_node = __insert(new_node);

			// std::cout << "=====================" << std::endl;
			// std::cout << new_node << std::endl;
			// std::cout << new_node->parent << std::endl;
			// std::cout << new_node->parent->left << std::endl;
			// std::cout << new_node->parent->right << std::endl;
			// std::cout << "=====================" << std::endl;

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

		void	erase(iterator pos) {
			
			__node_destroy(pos._M_node);
		}

		void	erase(iterator first, iterator last) {
			while (first != last)
				erase(first);
		}

	private :

		_node_pointer	__erase(_node_pointer node) {

		}

		_node_pointer	__insert(_node_pointer new_node) {
			if (empty()) {
				_root = __node_init(new_node, _nil, new_node->left);
				_last_left = _root;
				_last_right = _root;
				_nil->parent = _last_right;
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

		_node_pointer	__finde(key_type key) {
			if (empty())
				return _nil;
			return __iter_comp(_root, key);
		}

		_node_pointer	__iter_comp(_node_pointer p, key_type key) {
			if (_comp(key, p->value->first)) {
				if (p->left != _nil)
					return __iter_comp(p->left, key);
			}
			else if (_comp(p->value->first, key)) {
				if (p->right != _nil)
					return __iter_comp(p->right, key);
			}
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
			nil->parent = nullptr;
			nil->value = nullptr;
			nil->left = nullptr;
			nil->right = nullptr;
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
			_node_alloc.construct(new_node);
			new_node->value = _alloc.allocate(1);
			_alloc.construct(new_node->value, value);
			return new_node;
		}

		void			__node_destroy(_node_pointer elem) {
			_alloc.destroy(elem->value);
			_alloc.deallocate(elem->value, 1);
			_node_alloc.destroy(elem);
			_node_alloc.deallocate(elem, 1);
		}

} ;


}


#endif