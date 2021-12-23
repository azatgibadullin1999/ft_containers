/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:33:01 by root              #+#    #+#             */
/*   Updated: 2021/12/23 15:38:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE
# define RB_TREE



namespace ft {


template <typename T>
class Node {

	int		color;
	T		value;
	Node	*parent;
	Node	*right;
	Node	*left;

} ;


template <typename T>
class rb_tree {

	private :

		typedef Node<T>		node;
		typedef node*		pointer;
		typedef node&		reference;

		node		_nil;
		pointer		nil;
		size_t		high;

	public :

		rb_tree() nil(&_nil), root(&root) {
			nil->color = 1;
			nil->parent = nullptr;
			nil->right = nullptr;
			nil->left = nullptr;
		}


} ;


}


#endif