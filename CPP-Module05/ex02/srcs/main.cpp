/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:21:37 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 20:14:10 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AForm.hpp"
#include "../headers/Bureaucrat.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/includes.hpp"

static void enter_to_continue()
{
	cout << "\n\nPress |ENTER| to continue" << endl;
	std::cin.get();
	system("clear");
}

static void signPresidentialPardonForm()
{
	cout << Yellow << "Test signing PresidentialPardonForm" << Reset << endl << endl;
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		cout << Cyan << b1 << Reset;
		PresidentialPardonForm f1("Form1");
		cout << Cyan << f1 << Reset;
		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	cout << endl;

	try
	{
		Bureaucrat b2("Bureaucrat2", 150);
		cout << Cyan << b2 << Reset;
		PresidentialPardonForm f2("Form2");
		cout << Cyan << f2 << Reset;
		b2.signForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

static void signShrubberyCreationForm()
{
	cout << Yellow << "Test signing ShrubberyCreationForm" << Reset << endl << endl;
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		cout << Cyan << b1 << Reset;
		ShrubberyCreationForm f1("Form1");
		cout << Cyan << f1 << Reset;
		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	cout << endl;

	try
	{
		Bureaucrat b2("Bureaucrat2", 150);
		cout << Cyan << b2 << Reset;
		ShrubberyCreationForm f2("Form2");
		cout << Cyan << f2 << Reset;
		b2.signForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

static void signRobotomyRequestForm()
{
	cout << Yellow << "Test signing RobotomyRequestForm" << Reset << endl << endl;
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		cout << Cyan << b1 << Reset;
		RobotomyRequestForm f1("Form1");
		cout << Cyan << f1 << Reset;
		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}

	cout << endl;

	try
	{
		Bureaucrat b2("Bureaucrat2", 150);
		cout << Cyan << b2 << Reset;
		RobotomyRequestForm f2("Form2");
		cout << Cyan << f2 << Reset;
		b2.signForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

static void signAllForms()
{
	signPresidentialPardonForm();
	enter_to_continue();
	signShrubberyCreationForm();
	enter_to_continue();
	signRobotomyRequestForm();
}

static void executePresidentialPardonForm()
{
	cout << Yellow << "Test executing PresidentialPardonForm" << Reset << endl << endl;
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		cout << Cyan << b1 << Reset;
		PresidentialPardonForm f1("Form1");
		cout << Cyan << f1 << Reset;
		b1.executeForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
	cout << endl;
	try
	{
		Bureaucrat b2("Bureaucrat2", 150);
		cout << Cyan << b2 << Reset;
		PresidentialPardonForm f2("Form2");
		cout << Cyan << f2 << Reset;
		b2.executeForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
	cout << endl;
	try
	{
		Bureaucrat b3("Bureaucrat3", 1);
		cout << Cyan << b3 << Reset;
		PresidentialPardonForm f3("Form3");
		cout << Cyan << f3 << Reset;
		b3.signForm(f3);
		b3.executeForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
	cout << endl;
	try
	{
		Bureaucrat b4("Bureaucrat4", 150);
		cout << Cyan << b4 << Reset;
		PresidentialPardonForm f4("Form4");
		cout << Cyan << f4 << Reset;
		b4.signForm(f4);
		b4.executeForm(f4);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

static void executeRobotomyRequestForm()
{
	cout << Yellow << "Test executing RobotomyRequestForm" << Reset << endl << endl;
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		cout << Cyan << b1 << Reset;
		RobotomyRequestForm f1("Form1");
		cout << Cyan << f1 << Reset;
		b1.executeForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
	cout << endl;
	try
	{
		Bureaucrat b2("Bureaucrat2", 150);
		cout << Cyan << b2 << Reset;
		RobotomyRequestForm f2("Form2");
		cout << Cyan << f2 << Reset;
		b2.executeForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
	cout << endl;
	try
	{
		Bureaucrat b3("Bureaucrat3", 1);
		cout << Cyan << b3 << Reset;
		RobotomyRequestForm f3("Form3");
		cout << Cyan << f3 << Reset;
		b3.signForm(f3);
		b3.executeForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
	cout << endl;
	try
	{
		Bureaucrat b4("Bureaucrat4", 150);
		cout << Cyan << b4 << Reset;
		RobotomyRequestForm f4("Form4");
		cout << Cyan << f4 << Reset;
		b4.signForm(f4);
		b4.executeForm(f4);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

static void executeShrubberyCreationForm()
{
	cout << Yellow << "Test executing ShrubberyCreationForm" << Reset << endl << endl;
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		cout << Cyan << b1 << Reset;
		ShrubberyCreationForm f1("Form1");
		cout << Cyan << f1 << Reset;
		b1.executeForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
	cout << endl;
	try
	{
		Bureaucrat b2("Bureaucrat2", 150);
		cout << Cyan << b2 << Reset;
		ShrubberyCreationForm f2("Form2");
		cout << Cyan << f2 << Reset;
		b2.executeForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
	cout << endl;
	try
	{
		Bureaucrat b3("Bureaucrat3", 1);
		cout << Cyan << b3 << Reset;
		ShrubberyCreationForm f3("Form3");
		cout << Cyan << f3 << Reset;
		b3.signForm(f3);
		b3.executeForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
	cout << endl;
	try
	{
		Bureaucrat b4("Bureaucrat4", 150);
		cout << Cyan << b4 << Reset;
		ShrubberyCreationForm f4("Form4");
		cout << Cyan << f4 << Reset;
		b4.signForm(f4);
		b4.executeForm(f4);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << '\n' << Reset;
	}
}

static void executeAllForms()
{
	executePresidentialPardonForm();
	enter_to_continue();
	executeRobotomyRequestForm();
	enter_to_continue();
	executeShrubberyCreationForm();
}

int main()
{
	signAllForms();
	enter_to_continue();
	executeAllForms();
	enter_to_continue();
	return (0);
}