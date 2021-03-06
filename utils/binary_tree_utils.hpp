/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_utils.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:42:10 by root              #+#    #+#             */
/*   Updated: 2022/06/20 13:15:42 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_UTILS_HPP
# define BINARY_TREE_UTILS_HPP


# include "node.hpp"


# define LAST value
# define LAST_PARENT parent->value
# define LAST_LEFT left->value
# define LAST_RIGHT right->value


template <typename T>
ft::binary_node<T>	*__tree_down_to_last_left(ft::binary_node<T> *p) {
	if (p->LAST_LEFT != NULL)
		return __tree_down_to_last_left(p->left);
	return p;
}

template <typename T>
ft::binary_node<T>	*__tree_down_to_last_right(ft::binary_node<T> *p) {
	if (p->LAST_RIGHT != NULL)
		return __tree_down_to_last_right(p->right);
	return p;
}

template <typename T>
ft::binary_node<T>	*__tree_up_to_first_right(ft::binary_node<T> *pres, ft::binary_node<T> *prev) {
	if (pres->LAST != NULL && pres->right == prev)
		return __tree_up_to_first_right(pres->parent, pres);
	return pres;
}

template <typename T>
ft::binary_node<T>	*__tree_up_to_first_left(ft::binary_node<T> *pres, ft::binary_node<T> *prev) {
	if (pres->LAST != NULL && pres->left == prev)
		return __tree_up_to_first_left(pres->parent, pres);
	return pres;
}

template <typename T>
ft::binary_node<T>	*__tree_increment(ft::binary_node<T> *p) {
	if (p->LAST == NULL)
		return p->right;
	else if (p->LAST_RIGHT == NULL)
		return __tree_up_to_first_right(p, p->right);
	else
		return __tree_down_to_last_left(p->right);
}

template <typename T>
ft::binary_node<T>	*__tree_decrement(ft::binary_node<T> *p) {
	if (p->LAST == NULL)
		return p->left;
	else if (p->LAST_LEFT == NULL)
		return __tree_up_to_first_left(p, p->left);
	else
		return __tree_down_to_last_right(p->left);
}


#endif