/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:24:29 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 06:50:40 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include "../includes/inc.hpp"

static void enter_to_continue()
{
	cout << "\n\nPress |ENTER| to continue" << endl;
	std::cin.get();
	system("clear");
}

static void TestWithVector()
{
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	cout << Yellow << "Testing with a vector of integers" << Reset << endl;
	cout << "Vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << " ";
	cout << endl;

	try
	{
		cout << "Searching for 5: ";
		cout << Green << easyfind(vec, 5) << Reset << endl;
	}
	catch (std::exception &e)
	{
		cout << Red << "Element not found" << Reset << endl;
	}

	try
	{
		cout << "Searching for 10: ";
		cout << Green << easyfind(vec, 10) << Reset << endl;
	}
	catch (std::exception &e)
	{
		cout << Red << "Element not found" << Reset << endl;
	}
	enter_to_continue();
}

int main()
{
	TestWithVector();
	return (0);
}