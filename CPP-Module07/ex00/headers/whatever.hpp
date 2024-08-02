/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:31:35 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/22 19:05:02 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <cstdlib>
#include <string>

template <typename T>

void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>

T min(T &a, T &b)
{
	 if (a < b)
	 	return (a);
	return (b);
}

template <typename T>

T max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif