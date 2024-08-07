/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:32:35 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 08:22:05 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(string const target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original) : AForm(original) {
	*this = original;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this == &rhs)
		return (*this);
	return (*this);
}

string PresidentialPardonForm::getTarget() const {
	return (this->target);
}

void PresidentialPardonForm::executed(void) const
{
	cout << this->target << " has been pardoned by Zafod Beeblebrox." << endl;
}