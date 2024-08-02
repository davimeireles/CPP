/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 04:16:47 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 12:47:29 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Form.hpp"

Form::Form(string const name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	this->_signed = false;
}

Form::Form(const Form &original) : name(original.name), _signed(original._signed), gradeToSign(original.gradeToSign), gradeToExecute(original.gradeToExecute){}

Form& Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

string Form::getName() const
{
	return (this->name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeToSign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

ostream& operator<<(ostream &out, const Form &form)
{
	out << std::boolalpha;
	out << "Form: " << form.getName() << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute() << endl;
	return (out);
}

Form::~Form(){}