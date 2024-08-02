/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 04:27:19 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 04:43:46 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include "includes.hpp"

class AForm;

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
		void executeForm(AForm const & form) const;
		void signForm(AForm &form) const;

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