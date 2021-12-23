/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:04:14 by root              #+#    #+#             */
/*   Updated: 2021/12/21 16:33:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <iterator>

namespace ft {


template <typename T>
class Node {

	T		value;
	Node	*parent;
	Node	*right;
	Node	*left;

} ;

template <typename T>
class map_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
	
	private :

		typedef	Node<T>		_node;
		typedef	_node*		_node_pointer;

		_node_pointer	_p;

	public :

		map_iterator() : _p(nullptr) { }

		map_iterator(const value_type p) : _p(p) { }

		~map_iterator() { }

		map_iterator	&operator = (const map_iterator &other) {
			this->_p = other.base();
		}

		reference		operator * () { return _p->value; }

		pointer			operator -> () { return &_p->value; }

	private :

		_node_pointer	_tree_increment(_node_pointer p) {
			_node_pointer	prev = p;
			if (p->right != nullptr)
				return p;
			while (p != nullptr) {
				p = p->parent;
				if (p->right != prev)
			}
		}

} ;


}


#endif