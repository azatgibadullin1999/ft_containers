/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:20:12 by root              #+#    #+#             */
/*   Updated: 2021/12/03 15:29:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

# include "pair.hpp"

namespace ft {


template <typename T1, typename T2>
ft::pair<T1, T2>	make_pair(T1 _first, T2 _secnod) {
	return ft::pair<T1, T2>(_first, _secnod);
}


}

#endif