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
		AForm *f1 = intern.makeForm("presidential pardon", "target1");
		cout << Cyan << *f1 << Reset;
		Bureaucrat b1("b1", 4);
		b1.signForm(*f1);
		delete f1;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Intern intern;
		AForm *f2 = intern.makeForm("shrubbery creation", "target2");
		cout << Cyan << *f2 << Reset;
		Bureaucrat b2("b2", 132);
		b2.signForm(*f2);
		delete f2;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	try
	{
		Intern intern;
		AForm *f3 = intern.makeForm("robotomy request", "target3");
		cout << Cyan << *f3 << Reset;
		Bureaucrat b3("b3", 120);
		b3.signForm(*f3);
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