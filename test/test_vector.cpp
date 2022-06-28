/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:20:22 by larlena           #+#    #+#             */
/*   Updated: 2022/06/28 19:09:25 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
#include <cstdlib>
#include "../vector.hpp"

template <typename Container>
void	fill_array(Container &con, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		con.push_back(std::rand());
	}
}

template <typename stdIt, typename ftIt>
bool	array_diff(stdIt stdFirst, stdIt stdLast, ftIt ftFirst, ftIt ftLast) {
	for (; stdFirst != stdLast && ftFirst != ftLast; ++stdFirst, ++ftFirst) {
		if (*stdFirst != *ftFirst)
			return 1;
	}
	return 0;
}

void	vector_diff(const std::string test_name, const std::vector<int> &stdVec, const ft::vector<int> &ftVec) {
	std::cout << "==" << test_name << "==" << std::endl;
	std::cout << "size : " << ((stdVec.size() == ftVec.size()) ? "\033[32msame\033[m " : "\033[31mdifferent\033[m") << std::endl;
	std::cout << "capacity : " << ((stdVec.capacity() == ftVec.capacity()) ? "\033[32msame\033[m " : "\033[31mdifferent\033[m") << std::endl;
	std::cout << "max_size : " << ((stdVec.max_size() == ftVec.max_size()) ? "\033[32msame\033[m " : "\033[31mdifferent\033[m") << std::endl;
	std::cout << "array diff : " << (!array_diff(stdVec.begin(), stdVec.end(), ftVec.begin(), ftVec.end()) ? "\033[32msame\033[m " : "\033[31mdifferent\033[m") << std::endl;
	std::cout << std::endl;
}

void	test_constructor(const ft::vector<int> &ref_cont) {
	std::cout << "==============================" << std::endl;
	std::cout << "vector constructor testing" << std::endl;
	std::cout << "==============================" << std::endl;


	std::vector<int>	stdVec1;
	ft::vector<int>		ftVec1;
	vector_diff("default constructor", stdVec1, ftVec1);

	std::vector<int>	stdVec2(ref_cont.size());
	ft::vector<int>		ftVec2(ref_cont.size());
	vector_diff("constructor from size", stdVec2, ftVec2);

	std::vector<int>	stdVec3(ref_cont.begin(), ref_cont.end());
	ft::vector<int>		ftVec3(ref_cont.begin(), ref_cont.end());
	vector_diff("constructor from iter", stdVec3, ftVec3);

	std::vector<int>	stdVec4(stdVec3);
	ft::vector<int>		ftVec4(ftVec3);
	vector_diff("copy constructor", stdVec4, ftVec4);

}

void	test_modifiers(const ft::vector<int> &ref_cont) {
	std::cout << "==============================" << std::endl;
	std::cout << "vector modifiers testing" << std::endl;
	std::cout << "==============================" << std::endl;
	size_t	pos = ref_cont.size() / 10;
	int		elem = std::rand();

	std::vector<int>	stdVec1(ref_cont.begin(), ref_cont.end());
	ft::vector<int>		ftVec1(ref_cont.begin(), ref_cont.end());

	stdVec1.insert(stdVec1.begin() + pos, elem);
	ftVec1.insert(ftVec1.begin() + pos, elem);
	vector_diff("insert one element", stdVec1, ftVec1);

	stdVec1.insert(stdVec1.begin() + pos, pos * 2, elem);
	ftVec1.insert(ftVec1.begin() + pos, pos * 2, elem);
	vector_diff("insert several element", stdVec1, ftVec1);

	stdVec1.insert(stdVec1.begin() + pos, ref_cont.begin() + pos, ref_cont.end() - pos);
	ftVec1.insert(ftVec1.begin() + pos, ref_cont.begin() + pos, ref_cont.end() - pos);
	vector_diff("insert with iterator", stdVec1, ftVec1);

	stdVec1.push_back(elem);
	ftVec1.push_back(elem);
	vector_diff("push back", stdVec1, ftVec1);

	stdVec1.pop_back();
	ftVec1.pop_back();
	vector_diff("pop back", stdVec1, ftVec1);

	stdVec1.erase(stdVec1.begin() + pos, stdVec1.end() - pos);
	ftVec1.erase(ftVec1.begin() + pos, ftVec1.end() - pos);
	vector_diff("erase", stdVec1, ftVec1);

	stdVec1.clear();
	ftVec1.clear();
	vector_diff("clear", stdVec1, ftVec1);
}

void	test_vector() {
	size_t				size = 10000;
	ft::vector<int>		ref_cont(size);
	std::srand(1488);
	fill_array(ref_cont, size);

	std::cout << std::endl;
	std::cout << "\tVECTOR" << std::endl;
	std::cout << std::endl;

	test_constructor(ref_cont);
	test_modifiers(ref_cont);
}

