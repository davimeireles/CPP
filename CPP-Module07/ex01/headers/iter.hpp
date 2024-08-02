/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:09:16 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/22 21:20:08 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define Black "\033[30m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Magenta "\033[35m"
#define Cyan "\033[36m"
#define Reset "\033[0m"

template <typename T>
void iter(T *array, std::size_t length, void (*func)(T const &)) 
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void	printMsg(T &output) 
{
	std::cout << output << std::endl;
}