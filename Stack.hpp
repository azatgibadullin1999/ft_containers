/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:46:50 by root              #+#    #+#             */
/*   Updated: 2021/11/24 14:57:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "Vector.hpp"

namespace ft {

template <typename T, typename Container = ft::Vector<T> >
class Stack {

	public :

		typedef Container							container_type;
		typedef container_type::value_type			value_type;
		typedef container_type::size_type			size_type;
		typedef container_type::reference			reference;
		typedef container_type::const_reference		const_reference;

	private :

		container_type	_cont;

	public :

		explicit Stack(const container_type &cont = container_type()) :
		_cont(cont) { }

		Stack(const Stack &other) :
		_cont(cont) { }

		~Stack() { }

		Stack	&operator = (const Stack &other) {
			this->_cont = other->_cont;
			return this->_cont;
		}

		reference			top() { return this->_cont.end(); }

		const_reference		top() { return this->_cont.end(); }

		bool				empty() const { return this->_cont.empty(); }

		size_type			size() const { return this->_cont.size(); }

		void				push(const_reference value) { this->_cout.push_back(); }

		void				pop() { this->_cont.pop_back(); }

		

} ;

}

#endif