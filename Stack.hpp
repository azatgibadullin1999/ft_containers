/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:46:50 by root              #+#    #+#             */
/*   Updated: 2021/12/23 20:35:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "Vector.hpp"


namespace ft {


template <typename T, typename Container = ft::vector<T> >
class stack {

	public :

		typedef Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::size_type			size_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;

	protected :

		container_type	_cont;

	public :

		explicit stack(const container_type &cont = container_type()) :
		_cont(cont) { }

		stack(const stack &other) :
		_cont(other._cont) { }

		~stack() { }

		stack	&operator = (const stack &other) {
			this->_cont = other._cont;
			return *this;
		}

		reference			top() { return *--this->_cont.end(); }

		const_reference		top() const { return *--this->_cont.end(); }

		bool				empty() const { return this->_cont.empty(); }

		size_type			size() const { return this->_cont.size(); }

		void				push(const_reference value) { this->_cont.push_back(value); }

		void				pop() { this->_cont.pop_back(); }


		template <typename TCom, typename ContainerCom>
		friend bool	operator == (ft::stack<TCom, ContainerCom> lhs, ft::stack<TCom, ContainerCom> rhs);

		template <typename TCom, typename ContainerCom>
		friend bool	operator != (ft::stack<TCom, ContainerCom> lhs, ft::stack<TCom, ContainerCom> rhs);

		template <typename TCom, typename ContainerCom>
		friend bool	operator < (ft::stack<TCom, ContainerCom> lhs, ft::stack<TCom, ContainerCom> rhs);

		template <typename TCom, typename ContainerCom>
		friend bool	operator > (ft::stack<TCom, ContainerCom> lhs, ft::stack<TCom, ContainerCom> rhs);

		template <typename TCom, typename ContainerCom>
		friend bool	operator <= (ft::stack<TCom, ContainerCom> lhs, ft::stack<TCom, ContainerCom> rhs);

		template <typename TCom, typename ContainerCom>
		friend bool	operator >= (ft::stack<TCom, ContainerCom> lhs, ft::stack<TCom, ContainerCom> rhs);

} ;

template <typename T, typename Container>
bool	operator == (ft::stack<T, Container> lhs, ft::stack<T, Container> rhs) {
	return lhs._cont == rhs._cont;
}

template <typename T, typename Container>
bool	operator != (ft::stack<T, Container> lhs, ft::stack<T, Container> rhs) {
	return !(lhs == rhs);
}

template <typename T, typename Container>
bool	operator < (ft::stack<T, Container> lhs, ft::stack<T, Container> rhs) {
	return lhs._cont < rhs._cont;
}

template <typename T, typename Container>
bool	operator > (ft::stack<T, Container> lhs, ft::stack<T, Container> rhs) {
	return rhs < lhs;
}

template <typename T, typename Container>
bool	operator <= (ft::stack<T, Container> lhs, ft::stack<T, Container> rhs) {
	return !(lhs > rhs);
}

template <typename T, typename Container>
bool	operator >= (ft::stack<T, Container> lhs, ft::stack<T, Container> rhs) {
	return !(lhs < rhs);
}


}


#endif