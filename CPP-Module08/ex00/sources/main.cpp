/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:24:29 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/26 19:53:37 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);

	std::cout << Yellow << "Test With Valid Values" << Reset << std::endl << std::endl;
	easyfind(numbers, 1);
	easyfind(numbers, 2);
	easyfind(numbers, 3);
	easyfind(numbers, 4);
	easyfind(numbers, 5);
	
	std::endl(std::cout);
	std::cout << Yellow << "Test With Invalid Values" << Reset << std::endl << std::endl;
	easyfind(numbers, 20);
	easyfind(numbers, 15);
	easyfind(numbers, -20);
	easyfind(numbers, 17);
	easyfind(numbers, 14);
	std::endl(std::cout);
}