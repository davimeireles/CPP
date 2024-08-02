/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 04:38:44 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 08:19:45 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "includes.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		string	const target;

	public:
		RobotomyRequestForm(string const target = "RobotomyRequestForm Default");
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &original);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);

		string getTarget() const;
		void executed(void) const;
};


#endif