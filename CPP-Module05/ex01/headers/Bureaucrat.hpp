/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 04:02:12 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/30 07:19:07 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include "includes.hpp"

class Form;

class Bureaucrat
{
	private:
		string const name;
		int grade;

	public:
		Bureaucrat(string const name = "Default", int grade = 10);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &original);

		string getName() const;
		int getGrade()const;

		void setGrade(int grade);

		Bureaucrat& operator=(const Bureaucrat &rhs);

		void IncreaseGrade();
		void DecreaseGrade();
		void signForm(Form &form) const;

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

ostream&	operator<<(ostream &out, const Bureaucrat& Bureaucrat);

#endif