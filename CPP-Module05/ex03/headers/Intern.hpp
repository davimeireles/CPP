/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:44:03 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 08:54:31 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "includes.hpp"

class Intern
{
	private:
		AForm *Presidential(string target);
		AForm *Shrubbery(string target);
		AForm *Robotomy(string target);
	
	public:
		Intern(void);
		~Intern(void);
		AForm* (Intern::*funcArray[3])(string target);
		AForm* makeForm(string formName, string target);

	class NoFormException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
};

#endif