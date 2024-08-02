/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 04:28:08 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 09:05:36 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include "includes.hpp"

class Bureaucrat;

class AForm
{
	private:
		string const name;
		bool _signed;
		int const gradeToSign;
		int const gradeToExecute;
	
	public:
		AForm(string const name = "Default", int gradeToSign = 13, int gradeToExecute = 100);
		virtual ~AForm();
		AForm(const AForm &original);
		AForm& operator=(const AForm &rhs);

		string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &AForm);
		void execute(Bureaucrat const & executor) const;
		virtual void executed(void) const = 0;

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
	
	class SignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

ostream& operator<<(ostream &out, const AForm &form);

#endif