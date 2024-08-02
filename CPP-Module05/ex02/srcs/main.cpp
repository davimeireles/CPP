/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:21:37 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 08:27:22 by dmeirele         ###   ########.fr       */
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
	cout << "\n\nPress |ENTER| TWICE to continue" << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

int main()
{
	Bureaucrat signShrubberyBureaucrat("Sign ShrubberyBureaucrat", 145);
	Bureaucrat execShrubberyBureaucrat("Exec ShrubberyBureaucrat", 137);

	Bureaucrat signRobotomyBureaucrat("Sign RobotomyBureaucrat", 72);
	Bureaucrat execRobotomyBureaucrat("Exec RobotomyBureaucrat", 45);

	Bureaucrat signPresidentialBureaucrat("Sign PresidentialBureaucrat", 25);
	Bureaucrat execPresidentialBureaucrat("Exec PresidentialBureaucrat", 5);
	
	Bureaucrat highLevelBureaucrat("High Level", 1);
	Bureaucrat lowLevelBureaucrat("Low Level", 150);

	RobotomyRequestForm robotomyForm("Robot-1");
	PresidentialPardonForm presidentialForm("Presidential");
	ShrubberyCreationForm shrubberyForm("Shrubbery");

	system("clear");
	cout << Purple << "/*** Attemp to sign RobotomyRequestForm ***\\" << Reset << endl << endl;
	
	cout << Cyan << "Grade Needed (1-72)" << Reset << endl;
	
	cout << Orange << "[ High Level Bureaucrat - Grade 1 ]" << Reset << endl;
	highLevelBureaucrat.signForm(robotomyForm);
	endl(cout);
	cout << Orange << "[ Low Level Bureaucrat - Grade 150 ]" << Reset << endl;
	lowLevelBureaucrat.signForm(robotomyForm);
	endl(cout);
	cout << Orange << "[ Presidential Bureaucrat - Grade 25 ]" << Reset << endl;
	signPresidentialBureaucrat.signForm(robotomyForm);
	endl(cout);
	cout << Orange << "[ Robotomy Bureaucrat - Grade 72 ]" << Reset << endl;
	signRobotomyBureaucrat.signForm(robotomyForm);
	endl(cout);
	cout << Orange << "[ Shrubbery Bureaucrat - Grade 145 ]" << Reset << endl;
	signShrubberyBureaucrat.signForm(robotomyForm);
	endl(cout);
	enter_to_continue();
	cout << Purple << "/*** Attemp to sign PresidentialPardonForm ***\\" << Reset << endl << endl;
	
	cout << Cyan << "Grade Needed (1-25)" << Reset << endl;

	cout << Orange << "[ High Level Bureaucrat - Grade 1 ]" << Reset << endl;
	highLevelBureaucrat.signForm(presidentialForm);
	endl(cout);
	cout << Orange << "[ Low Level Bureaucrat - Grade 150 ]" << Reset << endl;
	lowLevelBureaucrat.signForm(presidentialForm);
	endl(cout);
	cout << Orange << "[ Presidential Bureaucrat - Grade 25 ]" << Reset << endl;
	signPresidentialBureaucrat.signForm(presidentialForm);
	endl(cout);
	cout << Orange << "[ Robotomy Bureaucrat - Grade 72 ]" << Reset << endl;
	signRobotomyBureaucrat.signForm(presidentialForm);
	endl(cout);
	cout << Orange << "[ Shrubbery Bureaucrat - Grade 145 ]" << Reset << endl;
	signShrubberyBureaucrat.signForm(presidentialForm);
	endl(cout);
	enter_to_continue();
	cout << Purple << "/*** Attemp to sign ShrubberyCreationForm ***\\" << Reset << endl << endl;

	cout << Cyan << "Grade Needed (1-145)" << Reset << endl;

	cout << Orange << "[ High Level Bureaucrat - Grade 1 ]" << Reset << endl;
	highLevelBureaucrat.signForm(shrubberyForm);
	endl(cout);
	cout << Orange << "[ Low Level Bureaucrat - Grade 150 ]" << Reset << endl;
	lowLevelBureaucrat.signForm(shrubberyForm);
	endl(cout);
	cout << Orange << "[ Presidential Bureaucrat - Grade 25 ]" << Reset << endl;
	signPresidentialBureaucrat.signForm(shrubberyForm);
	endl(cout);
	cout << Orange << "[ Robotomy Bureaucrat - Grade 72 ]" << Reset << endl;
	signRobotomyBureaucrat.signForm(shrubberyForm);
	endl(cout);
	cout << Orange << "[ Shrubbery Bureaucrat - Grade 145 ]" << Reset << endl;
	signShrubberyBureaucrat.signForm(shrubberyForm);
	endl(cout);
	enter_to_continue();
	cout << Purple << "/*** Attemp to execute RobotomyRequestForm ***\\" << Reset << endl << endl;

	cout << Cyan << "Grade Needed (1-45)" << Reset << endl;
	
	cout << Orange << "[ High Level Bureaucrat - Grade 1 ]" << Reset << endl;
	robotomyForm.execute(highLevelBureaucrat);
	endl(cout);
	cout << Orange << "[ Low Level Bureaucrat - Grade 150 ]" << Reset << endl;
	robotomyForm.execute(lowLevelBureaucrat);
	endl(cout);
	cout << Orange << "[ Presidential Bureaucrat - Grade 5 ]" << Reset << endl;
	robotomyForm.execute(execPresidentialBureaucrat);
	endl(cout);
	cout << Orange << "[ Robotomy Bureaucrat - Grade 45 ]" << Reset << endl;
	robotomyForm.execute(execRobotomyBureaucrat);
	endl(cout);
	cout << Orange << "[ Shrubbery Bureaucrat - Grade 137 ]" << Reset << endl;
	robotomyForm.execute(execShrubberyBureaucrat);
	endl(cout);
	enter_to_continue();
	cout << Purple << "/*** Attemp to execute PresidentialPardonForm ***\\" << Reset << endl << endl;

	cout << Cyan << "Grade Needed (1-5)" << Reset << endl;

	cout << Orange << "[ High Level Bureaucrat - Grade 1 ]" << Reset << endl;
	presidentialForm.execute(highLevelBureaucrat);
	endl(cout);
	cout << Orange << "[ Low Level Bureaucrat - Grade 150 ]" << Reset << endl;
	presidentialForm.execute(lowLevelBureaucrat);
	endl(cout);
	cout << Orange << "[ Presidential Bureaucrat - Grade 5 ]" << Reset << endl;
	presidentialForm.execute(execPresidentialBureaucrat);
	endl(cout);
	cout << Orange << "[ Robotomy Bureaucrat - Grade 45 ]" << Reset << endl;
	presidentialForm.execute(execRobotomyBureaucrat);
	endl(cout);
	cout << Orange << "[ Shrubbery Bureaucrat - Grade 137 ]" << Reset << endl;
	presidentialForm.execute(execShrubberyBureaucrat);
	endl(cout);
	enter_to_continue();
	cout << Purple << "/*** Attemp to execute ShrubberyCreationForm ***\\" << Reset << endl << endl;
	
	cout << Cyan << "Grade Needed (1-137)" << Reset << endl;

	cout << Orange << "[ High Level Bureaucrat - Grade 1 ]" << Reset << endl;
	shrubberyForm.execute(highLevelBureaucrat);
	endl(cout);
	cout << Orange << "[ Low Level Bureaucrat - Grade 150 ]" << Reset << endl;
	shrubberyForm.execute(lowLevelBureaucrat);
	endl(cout);
	cout << Orange << "[ Presidential Bureaucrat - Grade 5 ]" << Reset << endl;
	shrubberyForm.execute(execPresidentialBureaucrat);
	endl(cout);
	cout << Orange << "[ Robotomy Bureaucrat - Grade 45 ]" << Reset << endl;
	shrubberyForm.execute(execRobotomyBureaucrat);
	endl(cout);
	cout << Orange << "[ Shrubbery Bureaucrat - Grade 137 ]" << Reset << endl;
	shrubberyForm.execute(execShrubberyBureaucrat);
	endl(cout);
	enter_to_continue();

	return (0);
}