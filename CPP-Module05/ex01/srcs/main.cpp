/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 04:55:07 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 19:39:40 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"
#include "../headers/includes.hpp"

static void enter_to_continue()
{
	cout << "\n\nPress |ENTER| to continue" << endl;
	std::cin.get();
	system("clear");
}

static void createForm()
{
	cout << Yellow << "Test creating forms" << Reset << endl << endl;
	try
	{
		Form f1("Form1", 1, 1);
		cout << Cyan << f1 << Reset;
		Form f2("Form2", 150, 150);
		cout << Cyan << f2 << Reset;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	cout << endl;

	try
	{
		Form f3("Form3", 0, 0);
		cout << Cyan << f3 << endl << Reset;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Form f4("Form4", 151, 151);
		cout << Cyan << f4 << endl << Reset;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

static void testBeSigned()
{
	cout << Yellow << "Test singning valid forms" << Reset << endl << endl;
	try
	{
		Form f1("Form1", 1, 1);
		Bureaucrat b1("Bureaucrat1", 1);
		cout << f1;
		cout << b1 << endl << endl;
		f1.beSigned(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Form f2("Form2", 150, 150);
		Bureaucrat b2("Bureaucrat2", 150);
		cout << f2;
		cout << b2 << endl << endl;
		f2.beSigned(b2);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Form f4("Form4", 150, 150);
		Bureaucrat b4("Bureaucrat4", 1);
		cout << f4;
		cout << b4 << endl << endl;
		f4.beSigned(b4);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	cout << Yellow << "Test singning invalid form" << Reset << endl;
	try
	{
		Form f3("Form3", 1, 1);
		Bureaucrat b3("Bureaucrat3", 150);
		cout << f3;
		cout << b3 << endl;
		f3.beSigned(b3);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

int main()
{
	createForm();
	enter_to_continue();
	testBeSigned();
	enter_to_continue();
	return (0);
}