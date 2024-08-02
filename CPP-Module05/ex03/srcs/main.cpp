/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:21:37 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 20:17:41 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AForm.hpp"
#include "../headers/Bureaucrat.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/includes.hpp"
#include "../headers/Intern.hpp"

static void enter_to_continue()
{
	cout << "\n\nPress |ENTER| to continue" << endl;
	std::cin.get();
	system("clear");
}

static void testMakeForms()
{
	try
	{
		Intern intern;
		AForm *f1 = intern.makeForm("PresidentialPardonForm", "target1");
		cout << Cyan << *f1 << Reset;
		delete f1;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Intern intern;
		AForm *f2 = intern.makeForm("ShrubberyCreationForm", "target2");
		cout << Cyan << *f2 << Reset;
		delete f2;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Intern intern;
		AForm *f3 = intern.makeForm("RobotomyRequestForm", "target3");
		cout << Cyan << *f3 << Reset;
		delete f3;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

int main()
{
	testMakeForms();
	enter_to_continue();
}