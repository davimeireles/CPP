/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 04:38:46 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 08:21:03 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "includes.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		string const target;

	public:
		ShrubberyCreationForm(string const target = "ShrubberyCreationForm Default");
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &original);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);

		string getTarget() const;
		void executed(void) const;
};

#endif