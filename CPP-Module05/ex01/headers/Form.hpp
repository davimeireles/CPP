/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 04:02:10 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/30 07:17:05 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include "includes.hpp"

class Bureaucrat;

class Form
{
	private:
		string const name;
		bool _signed;
		int const gradeToSign;
		int const gradeToExecute;
	
	public:
		Form(string const name = "Default", int gradeToSign = 13, int gradeToExecute = 100);
		~Form();
		Form(const Form &original);
		Form& operator=(const Form &rhs);

		string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

ostream& operator<<(ostream &out, const Form &form);

#endif