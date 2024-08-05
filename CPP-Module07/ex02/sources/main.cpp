/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 03:17:17 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 04:06:59 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include "../includes/inc.hpp"

static void enter_to_continue()
{
	cout << "\n\nPress |ENTER| to continue" << endl;
	std::cin.get();
	system("clear");
}

static void TestEmptyArray()
{
	Array<int> array;
	
	try
	{
		cout << array[0] << endl;
	}
	catch(const std::exception& e)
	{
		cout << Red << e.what() << Reset << endl;
	}
}

static void TestDefaultArray()
{
	Array<int> array(5);
	
	for(unsigned int i = 0; i < array.size(); i++)
		array[i] = rand() % 100;
	
	for(unsigned int i = 0; i < array.size(); i++)
		cout << Cyan << "index[" << i << "]: " << array[i] << endl << Reset;
}

static void TestCopyArray()
{
	Array<int> array(5);
	
	for(unsigned int i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		cout << Cyan << "Original index[" << i << "]: " << array[i] << endl << Reset;
	}
	
	Array<int> copy(array);
	
	for(unsigned int i = 0; i < copy.size(); i++)
		cout << "Copy index[" << i << "]: " << copy[i] << endl;
}

static void TestAssignArray()
{
	Array<int> array(5);
	
	for(unsigned int i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		cout << Cyan << "Original index[" << i << "]: " << array[i] << endl << Reset;
	}
	
	Array<int> copy(3);
	
	copy = array;
	
	for(unsigned int i = 0; i < copy.size(); i++)
		cout << "Copy index[" << i << "]: " << copy[i] << endl;
}

static void TestAccessingElements()
{
	Array<int> array(5);
	
	for(unsigned int i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		cout << Cyan << "index[" << i << "]: " << array[i] << endl << Reset;
	}
	try
	{
		cout << Purple << "Trying to access an element within the array limits" << endl;
		cout << "Element at index 4: " << Reset << endl;
		cout << array[4] << endl;
	}
	catch(const std::exception& e)
	{
		cout << Red << e.what() << Reset << endl;
	}

	try
	{
		cout << Purple <<"Trying to access an element out of the array limits" << endl;
		cout << "Element at index 5: " << Reset << endl;
		cout << array[5] << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset << '\n';
	}
	
}

static void TestMemberFunction()
{
	Array<int> array(5);

	cout << Orange << "Array size: " << array.size() << endl << Reset;
}

int main()
{
	cout << Yellow << "--- Test Empty Array ---" << Reset << endl;
	TestEmptyArray();
	enter_to_continue();
	cout << Yellow << "--- Test Default Array ---" << Reset << endl;
	TestDefaultArray();
	enter_to_continue();
	cout << Yellow << "--- Test Copy Array ---" << Reset << endl;
	TestCopyArray();
	enter_to_continue();
	cout << Yellow << "--- Test Assign Array ---" << Reset << endl;
	TestAssignArray();
	enter_to_continue();
	cout << Yellow << "--- Test Accessing Elements ---" << Reset << endl;
	TestAccessingElements();
	enter_to_continue();
	cout << Yellow << "--- Test Member Function ---" << Reset << endl;
	TestMemberFunction();
	enter_to_continue();
	return (0);
}