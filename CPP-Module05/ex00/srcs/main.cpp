/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:44:55 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 19:25:56 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/includes.hpp"

static void enter_to_continue()
{
	cout << "\n\nPress |ENTER| to continue" << endl;
	std::cin.get();
	system("clear");
}

static void testCreateBureaucrat()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		cout << b1 << endl;
		Bureaucrat b2("Bureaucrat2", 150);
		cout << b2 << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Bureaucrat b3("Bureaucrat3", 0);
		cout << b3 << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Bureaucrat b4("Bureaucrat4", 151);
		cout << b4 << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

static void testIncreaseGrade()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		cout << b1 << endl;
		b1.IncreaseGrade();
		cout << b1 << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Bureaucrat b2("Bureaucrat2", 150);
		cout << b2 << endl;
		b2.IncreaseGrade();
		cout << b2 << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

static void testDecreaseGrade()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		cout << b1 << endl;
		b1.DecreaseGrade();
		cout << b1 << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Bureaucrat b2("Bureaucrat2", 150);
		cout << b2 << endl;
		b2.DecreaseGrade();
		cout << b2 << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

int main()
{
	cout << Yellow << "Test Create Bureaucrat" << Reset << endl;
	testCreateBureaucrat();
	enter_to_continue();
	cout << Yellow << "Test Increase Grade" << Reset << endl;
	testIncreaseGrade();
	enter_to_continue();
	cout << Yellow << "Test Decrease Grade" << Reset << endl;
	testDecreaseGrade();
	enter_to_continue();
	return (0);
}