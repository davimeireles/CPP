/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 04:38:38 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 08:21:36 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "includes.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		string	const target;

	public:
		PresidentialPardonForm(string const target = "PresidentialPardonForm Default");
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &original);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);

		string getTarget() const;
		void executed(void) const;
};

#endif