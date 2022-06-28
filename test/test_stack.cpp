/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:20:14 by larlena           #+#    #+#             */
/*   Updated: 2022/06/28 18:03:12 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <cstdlib>
#include "../stack.hpp"

void	stack_diff(const std::string test_name, const std::stack<int> &stdStack, const ft::stack<int> &ftStack) {
	std::cout << "==" << test_name << "==" << std::endl;
	std::cout << "size : " << ((stdStack.size() == ftStack.size()) ? "\033[32msame\033[m " : "\033[31mdifferent\033[m") << std::endl;
	std::cout << "top : " << ((stdStack.top() == ftStack.top()) ? "\033[32msame\033[m " : "\033[31mdifferent\033[m") << std::endl;
	std::cout << std::endl;
}

void	test_constructor() {
	std::cout << "==============================" << std::endl;
	std::cout << "stack constructor testing" << std::endl;
	std::cout << "==============================" << std::endl;


	std::stack<int>		stdStack1;
	ft::stack<int>		ftStack1;
	stdStack1.push(1488);
	stdStack1.push(228);
	stdStack1.push(1337);
	ftStack1.push(1488);
	ftStack1.push(228);
	ftStack1.push(1337);
	stack_diff("default constructor", stdStack1, ftStack1);
	

	std::stack<int>		stdStack2(stdStack1);
	ft::stack<int>		ftStack2(ftStack1);
	stack_diff("copy constructor", stdStack2, ftStack2);

}

void	test_modifiers() {
	std::cout << "==============================" << std::endl;
	std::cout << "stack modifiers testing" << std::endl;
	std::cout << "==============================" << std::endl;

	std::stack<int>		stdStack1;
	ft::stack<int>		ftStack1;

	stdStack1.push(std::rand());
	ftStack1.push(stdStack1.top());
	ftStack1.push(std::rand());
	stdStack1.push(ftStack1.top());
	stdStack1.push(std::rand());
	ftStack1.push(stdStack1.top());
	ftStack1.push(std::rand());
	stdStack1.push(ftStack1.top());
	stack_diff("push back", stdStack1, ftStack1);

	stdStack1.pop();
	ftStack1.pop();
	stdStack1.pop();
	ftStack1.pop();
	stdStack1.pop();
	ftStack1.pop();
	stack_diff("pop back", stdStack1, ftStack1);

}

void	test_stack() {	
	std::cout << std::endl;
	std::cout << "\tSTACK" << std::endl;
	std::cout << std::endl;


	test_constructor();
	test_modifiers();
}