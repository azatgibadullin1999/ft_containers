/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:55:38 by larlena           #+#    #+#             */
/*   Updated: 2022/06/28 18:43:12 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stack>
#include <map>
#include "../vector.hpp"
#include "../stack.hpp"
#include "../map.hpp"

void	test_vector();
void	test_stack();
void	test_map();

int main(int argc, char **argv)
{
	test_vector();
	test_stack();
	test_map();
	std::cout << "go check to leaks" << std::endl;
	for (;;) { }
}