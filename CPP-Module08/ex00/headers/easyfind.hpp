/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:25:07 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/26 19:54:16 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

/* Headers Includes */
#include <iostream>
#include <vector>

/* Colors */
#define Black "\033[30m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Magenta "\033[35m"
#define Cyan "\033[36m"
#define Reset "\033[0m"
#define Orange "\033[38;5;208m"

template <typename T>
void easyfind(T& container, int n)
{
	typedef typename T::iterator iterator;

	try
	{
		for (iterator it = container.begin(); it != container.end(); it++)
		{
			if (*it == n)
			{
				int index = std::distance(container.begin(), it);
				std::cout << Green << "Element found [" << *it << "] on position [" << index << "]" << Reset << std::endl;
				return ;
			}
		}
		throw std::runtime_error("Occurrence not found.");
	}
	catch(const std::exception& e)
	{
		std::cerr << Red <<  e.what() << Reset << std::endl;
	}
}

#endif