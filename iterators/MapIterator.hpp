/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:04:14 by root              #+#    #+#             */
/*   Updated: 2022/02/08 22:09:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <iterator>
# include "../utils.hpp"
# include "../Map.hpp"


namespace ft {


template <typename Key, typename T>
class binary_tree_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
	
	private :

		typedef ft::binary_node< ft::pair<Key, T> >	_node;
		typedef _node*								_node_pointer;
		typedef _node&								_node_reference;

		# define LAST value
		# define LAST_PARENT parent->value
		# define LAST_LEFT left->value
		# define LAST_RIGHT right->value

	public :

		typedef typename _node::value_type		value_type;
		typedef typename _node::value_type*		pointer;
		typedef typename _node::value_type&		reference;
		typedef std::ptrdiff_t					difference_type;
		typedef std::bidirectional_iterator_tag	iterator_category;

		binary_tree_iterator() :
			_M_node(nullptr) { }

		binary_tree_iterator(const _node_pointer p) :
			_M_node(p) { }

		binary_tree_iterator(const binary_tree_iterator &other) :
			_M_node(other._M_node) { }

		~binary_tree_iterator() { }

		const binary_tree_iterator	&operator = (const binary_tree_iterator &other) {
			this->_M_node = other._M_node;
			return *this;
		}

		reference		operator * () { return *_M_node->value; }

		pointer			operator -> () { return _M_node->value; }

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

	private :

		_node_pointer	__tree_increment(_node_pointer p) {
			if (p->LAST != nullptr && p->LAST_RIGHT == nullptr)
				return __tree_up_to_first_right(p, p->right);
			else
				return __tree_down_to_last_left(p->right);
		}

		_node_pointer	__tree_decrement(_node_pointer p) {
			if (p->LAST != nullptr && p->LAST_LEFT == nullptr)
				return __tree_up_to_first_left(p, p->left);
			else
				return __tree_down_to_last_right(p->left);
		}

		_node_pointer	__tree_up_to_first_right(_node_pointer pres, _node_pointer prev) {
			if (pres->right == prev)
				return __tree_up_to_first_right(pres->parent, pres);
			return pres;
		}

		_node_pointer	__tree_up_to_first_left(_node_pointer pres, _node_pointer prev) {
			if (pres->left == prev)
				return __tree_up_to_first_left(pres->parent, pres);
			return pres;
		}

		_node_pointer	__tree_down_to_last_left(_node_pointer p) {
			if (p->LAST_LEFT != nullptr)
				return __tree_down_to_last_left(p->left);
			return p;
		}

		_node_pointer	__tree_down_to_last_right(_node_pointer p) {
			if (p->LAST_RIGHT != nullptr)
				return __tree_down_to_last_right(p->right);
			return p;
		}

} ;


}


#endif