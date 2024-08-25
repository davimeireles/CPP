/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:13:22 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/24 14:10:39 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	std::string strings[] = {"Davi", "Ana", "Gregorio", "Familia", "Feliz"};
	float floats[] = {0.2, 1.4, 1.7, 2.1, 2.5};
	int numbers[]= {02, 14, 17, 21, 25};

	std::cout << Green << "--- Testing iter ---" << Reset << std::endl << std::endl;

	std::cout << Yellow << "With Strings" << Reset << std::endl;
	iter(strings, 5, printMsg);
	std::endl(std::cout);

	std::cout << Yellow << "With Floats" << Reset << std::endl;
	iter(floats, 5, printMsg);
	std::endl(std::cout);

	std::cout << Yellow << "With Integers" << Reset << std::endl;
	iter(numbers, 5, printMsg);
	std::endl(std::cout);

	return (0);
}