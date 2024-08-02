/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:48:19 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/01 18:57:09 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Intern.hpp"

Intern::Intern(void)
{
	funcArray[0] = &Intern::Presidential;
	funcArray[1] = &Intern::Shrubbery;
	funcArray[2] = &Intern::Robotomy;
}

AForm* Intern::Presidential(string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::Shrubbery(string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::Robotomy(string target)
{
	return new RobotomyRequestForm(target);
}

Intern::~Intern(void){}

const char* Intern::NoFormException::what() const throw()
{
	return("Form not found.");
}

AForm* Intern::makeForm(string formName, string target) {

	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};	

	for(int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
			return (this->*funcArray[i])(target);
	}
	throw Intern::NoFormException();
}