/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:21:51 by root              #+#    #+#             */
/*   Updated: 2021/12/03 16:34:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <memory>
#include <exception>
#include "Vector.hpp"
#include <stdlib.h>
// #include <type_traits>
#include <map>

void	ft1() {
	std::vector<int>			a(200, 10);
	std::vector<int>			c(a);
	ft::Vector<int>				b(30, 10);
	std::allocator<int>			alloc;

	std::cout << a.capacity() << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << b.capacity() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << "start insert" << std::endl;

	std::vector<int>::iterator	it;

	b.insert(b.begin() + 10, 100, 100);

	b.push_back(2000);

	std::cout << b.capacity() << std::endl;

	a.insert(a.begin() + 10, 100, 3000);

	a.push_back(2000);

	b.insert(b.begin(), a.begin() + 20, a.begin() + 30);

	a.insert(a.begin(), b.begin() + 20, b.begin() + 30);

	for (size_t i = 0; i < b.size(); i++) {
		std::cout << i << " : " << b[i] << std::endl;
	}
	// for (size_t i = 0; i < a.size(); i++) {
	// 	std::cout << i << " : " << a[i] << std::endl;
	// }
}

int		main() {
	ft1();
	return 0;
}
