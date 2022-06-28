/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:04:14 by root              #+#    #+#             */
/*   Updated: 2022/06/28 19:56:07 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <iterator>
# include "../utils.hpp"
# include "../map.hpp"


namespace ft {


template <typename T>
class binary_tree_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
	
	private :

		typedef ft::binary_node<T>		_node;
		typedef _node*					_node_pointer;
		typedef _node&					_node_reference;

	public :

		typedef typename _node::value_type			value_type;
		typedef typename _node::value_type*			pointer;
		typedef typename _node::value_type&			reference;
		typedef std::ptrdiff_t						difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;

		binary_tree_iterator() :
			_M_node(NULL) { }

		binary_tree_iterator(const _node_pointer p) :
			_M_node(p) { }

		binary_tree_iterator(const binary_tree_iterator &other) :
			_M_node(other._M_node) { }

		~binary_tree_iterator() { }

		const binary_tree_iterator	&operator = (const binary_tree_iterator &other) {
			this->_M_node = other._M_node;
			return *this;
		}

		reference		operator * () const { return *_M_node->value; }

		pointer			operator -> () const { return _M_node->value; }

		binary_tree_iterator	&operator ++ () {
			this->_M_node = __tree_increment(this->_M_node);
			return *this;
		}

		binary_tree_iterator	operator ++ (int) {
			binary_tree_iterator	dst = *this;
			this->_M_node = __tree_increment(this->_M_node);
			return dst;
		}

		binary_tree_iterator	&operator -- () {
			this->_M_node = __tree_decrement(this->_M_node);
			return *this;
		}

		binary_tree_iterator	operator -- (int) {
			binary_tree_iterator	dst = *this;
			this->_M_node = __tree_decrement(this->_M_node);
			return dst;
		}


		bool		operator == (const binary_tree_iterator &other) const {
			return this->_M_node == other._M_node;
		}

		bool		operator != (const binary_tree_iterator &other) const {
			return this->_M_node != other._M_node;
		}

		
		_node_pointer	_M_node;

} ;


template <typename T>
class binary_tree_const_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
	
	private :

		typedef ft::binary_node<T>		_node;
		typedef _node*					_node_pointer;
		typedef _node&					_node_reference;

		# define LAST value
		# define LAST_PARENT parent->value
		# define LAST_LEFT left->value
		# define LAST_RIGHT right->value

	public :

		typedef const typename _node::value_type		value_type;
		typedef const typename _node::value_type*		pointer;
		typedef const typename _node::value_type&		reference;
		typedef std::ptrdiff_t							difference_type;
		typedef std::bidirectional_iterator_tag			iterator_category;

		binary_tree_const_iterator() :
			_M_node(NULL) { }

		binary_tree_const_iterator(const _node_pointer p) :
			_M_node(p) { }

		binary_tree_const_iterator(const binary_tree_iterator<T> &it) :
			_M_node(it._M_node) { }

		binary_tree_const_iterator(const binary_tree_const_iterator &other) :
			_M_node(other._M_node) { }

		~binary_tree_const_iterator() { }

		const binary_tree_const_iterator	&operator = (const binary_tree_const_iterator &other) {
			this->_M_node = other._M_node;
			return *this;
		}

		reference		operator * () const { return *_M_node->value; }

		pointer			operator -> () const { return _M_node->value; }

		binary_tree_const_iterator	&operator ++ () {
			this->_M_node = __tree_increment(this->_M_node);
			return *this;
		}

		binary_tree_const_iterator	operator ++ (int) {
			binary_tree_const_iterator	dst = *this;
			this->_M_node = __tree_increment(this->_M_node);
			return dst;
		}

		binary_tree_const_iterator	&operator -- () {
			this->_M_node = __tree_decrement(this->_M_node);
			return *this;
		}

		binary_tree_const_iterator	operator -- (int) {
			binary_tree_const_iterator	dst = *this;
			this->_M_node = __tree_decrement(this->_M_node);
			return dst;
		}


		bool		operator == (const binary_tree_const_iterator &other) const {
			return this->_M_node == other._M_node;
		}

		bool		operator != (const binary_tree_const_iterator &other) const {
			return this->_M_node != other._M_node;
		}

		
		_node_pointer	_M_node;

} ;


}


#endif