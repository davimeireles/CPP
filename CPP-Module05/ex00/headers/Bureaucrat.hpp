/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 04:02:17 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/30 07:19:53 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

#define Red "\033[31m"
#define Green "\033[32m"
#define Orange "\033[38;5;208m"
#define Reset "\033[0m"

using std::string;
using std::cout;
using std::endl;
using std::ostream;

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
