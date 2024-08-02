/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:30:09 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 19:44:09 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(string const name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &original) : name(original.name)
{
	this->grade = original.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		this->grade = rhs.grade;
	return (*this);
}

string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::setGrade(int grade)
{
	this->grade = grade;
}

ostream& operator<<(ostream &out, const Bureaucrat &Bureaucrat)
{
	out << Green << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << Reset << endl;
	return (out);
}

void Bureaucrat::IncreaseGrade()
{
	if (this->grade > 1)
		this->grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::DecreaseGrade()
{
	if (this->grade < 150)
		this->grade++;
	else
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

void Bureaucrat::signForm(AForm &Aform) const
{
	try
	{
		Aform.beSigned(*this);
		cout << Green <<this->name << " signed " << Aform << Reset;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << this->name << " couldn't sign " << Aform << "because " << e.what() << Reset <<'\n';
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	form.execute(*this);
}

Bureaucrat::~Bureaucrat(){}