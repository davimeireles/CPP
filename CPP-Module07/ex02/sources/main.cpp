/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:33:06 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/23 01:44:22 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	std::cout << Yellow << "/******* ARRAY INT TESTING *******\\" << Reset << std::endl << std::endl;

	std::cout <<  Blue << "--- Testing Default Constructor ---" << Reset << std::endl;
	Array<int> defaultArray;
	std::cout << Orange << "Default array size: " << defaultArray.size() << Reset << std::endl << std::endl;

	std::cout <<  Blue << "--- Testing Parameterized Constructor ---" << Reset << std::endl;
	Array<int> paramArray(5);
	std::cout << Orange << "Parameterized array size: " << paramArray.size() << Reset << std::endl << std::endl;

	std::cout <<  Blue << "--- Testing Copy Constructor ---" << Reset << std::endl;
	Array<int> copyArray = paramArray;
	std::cout << Orange << "Copy array size: " << copyArray.size() << Reset << std::endl << std::endl;

	std::cout <<  Blue << "--- Testing Assignment Operator ---" << Reset << std::endl;
	Array<int> assignArray;
	assignArray = paramArray;
	std::cout << Orange << "Assigned array size: " << assignArray.size() << Reset << std::endl << std::endl;

	std::cout <<  Blue << "--- Testing Element Access and Modification ---" << Reset << std::endl;
	try
	{
		paramArray[0] = 10;
		std::cout << Orange << "Element at index 0: " << paramArray[0] << Reset << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	try
	{
		std::cout << Red <<"Accessing out of bounds: " << paramArray[10] << Reset << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	std::cout << Yellow << "/******* ARRAY STRING TESTING *******\\" << Reset << std::endl << std::endl;

	std::string sArray[] = {"Gregorio", "Davi", "Ana", "Familia", "Porto", "Portugal"};

	std::cout <<  Blue << "--- Testing Default Constructor ---" << Reset << std::endl;
	Array<std::string> defaultSArray;
	std::cout << Orange << "Default array size: " << defaultSArray.size() << Reset << std::endl << std::endl;

	std::cout <<  Blue << "--- Testing Parameterized Constructor ---" << Reset << std::endl;
	Array<std::string> paramSArray(4);
	std::cout << Orange << "Parameterized array size: " << paramSArray.size() << Reset << std::endl << std::endl;

	std::cout <<  Blue << "--- Testing Copy Constructor ---" << Reset << std::endl;
	Array<std::string> copySArray = paramSArray;
	std::cout << Orange << "Copy array size: " << copySArray.size() << Reset << std::endl << std::endl;

	std::cout <<  Blue << "--- Testing Assignment Operator ---" << Reset << std::endl;
	Array<std::string> assignSArray;
	assignSArray = paramSArray;
	std::cout << Orange << "Assigned array size: " << assignSArray.size() << Reset << std::endl << std::endl;

	std::cout <<  Blue << "--- Testing Element Access and Modification ---" << Reset << std::endl;
	try
	{
		paramSArray[0] = "O grande Gregorio";
		paramSArray[3] = "O grande Davi";
		paramSArray[1] = "A grande Ana";
		std::cout << Orange << "Element at index 0: " << paramSArray[0] << Reset << std::endl << std::endl;
		std::cout << Orange << "Element at index 1: " << paramSArray[1] << Reset << std::endl << std::endl;
		std::cout << Orange << "Element at index 3: " << paramSArray[3] << Reset << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	try
	{
		std::cout << Red <<"Accessing out of bounds: " << paramSArray[10] << Reset << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	return (0);
}