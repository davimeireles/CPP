/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:17:58 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 22:36:01 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScalarConverter.hpp"
#include "../headers/includes.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert [input]" << std::endl;
		return (1);
	}
	else
		ScalarConverter::convert(argv[1]);
}