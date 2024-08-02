/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:32:30 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/31 08:24:42 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(string const target) : AForm("ShrubberyCreationForm", 145, 137) , target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) : AForm(original) {
	*this = original;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return (*this);
}

string ShrubberyCreationForm::getTarget() const {
	return (this->target);
}

void ShrubberyCreationForm::executed(void) const
{
	std::ofstream file;
	file.open((this->target + "shrubbery").c_str(), std::ios::out);
	
	if (file.fail())
		throw std::runtime_error("Fail to open " + this->target + "_shrubbery");

	string sakuraTree = 
	        "         ,@@@@@@@,\n"
        " ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
        ",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
        ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
        "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
        "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
        "`&%\\ ` /%&'    |.|        \\ '|8'\n"
        "    |o|        | |         | |\n"
        "    |.|        | |         | |\n"
        " \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";

	file << sakuraTree;
	file.close();
}