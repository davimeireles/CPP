/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 04:51:04 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 04:53:13 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AForm.hpp"

AForm::AForm(string const name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(const AForm &original) : name(original.name), _signed(original._signed), gradeToSign(original.gradeToSign), gradeToExecute(original.gradeToExecute){}

AForm& AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char* AForm::SignedException::what() const throw()
{
	return ("Form is not signed.");
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeToSign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

ostream& operator<<(ostream &out, const AForm &Aform)
{
	out << std::boolalpha;
	out << "AForm: " << Aform.getName() << ", Grade to Sign: " << Aform.getGradeToSign() << ", Grade to Execute: " << Aform.getGradeToExecute() << endl;
	return (out);
}

AForm::~AForm(){}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();
	else if (!this->_signed)
		throw SignedException();
	cout << Yellow << executor.getName() << " executed " << this->name << Reset << endl;
	this->executed();
}