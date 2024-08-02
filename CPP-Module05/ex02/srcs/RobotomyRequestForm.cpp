/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:32:33 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 08:24:51 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(string const target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) : AForm(original) {
	*this = original;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return (*this);
}

string RobotomyRequestForm::getTarget() const {
	return (this->target);
}

void RobotomyRequestForm::executed(void) const
{
	cout << "*drilling noises*" << endl;
	if (rand() % 2)
		cout << this->target << " has been robotomized successfully." << endl;
	else
		cout << this->target << " robotomization failed." << endl;
}