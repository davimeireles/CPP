/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 04:55:07 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/30 07:33:49 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"

int main()
{
	system("clear");
	// "[ --- Constructor Bureaucrat --- ]"
	Bureaucrat highGradeBureaucrat("highGradeBureaucrat", 1);
	Bureaucrat lowGradeBureaucrat("lowGradeBureucrat", 150);
	Bureaucrat invalidBureaucrat("invalidBureaucrat", 42);
	//"[ --- Constructor Form --- ]"
	Form highRequirementForm("High Requirement", 1, 1);
	Form lowRequirementForm("Low Requirement", 150, 150);

	cout << Orange << "[ --- Operator << Tests --- ]" << Reset << endl;
	cout << highGradeBureaucrat << endl;
	cout << lowGradeBureaucrat << endl;
	cout << invalidBureaucrat << endl;
	cout << endl;

	cout << Purple << highRequirementForm;
	cout << Purple << lowRequirementForm;
	cout << endl;

	cout << Orange << "[ --- SignForm Test --- ]" << Reset << endl;
	highGradeBureaucrat.signForm(highRequirementForm);
	lowGradeBureaucrat.signForm(lowRequirementForm);
	cout << endl;

	invalidBureaucrat.signForm(highRequirementForm);
	invalidBureaucrat.signForm(lowRequirementForm);
	cout << endl;

	cout << Orange << "[ --- Increase & Decrease Grade Test --- ]" << Reset << endl;
	cout << Purple << "highGradeBureucrat Grade -> " << highGradeBureaucrat.getGrade() << Reset << endl;
	highGradeBureaucrat.IncreaseGrade();
	cout << Purple << "lowGradeBureucrat Grade -> " << lowGradeBureaucrat.getGrade() << Reset << endl;
	lowGradeBureaucrat.DecreaseGrade();
	cout << endl;

	cout << Orange << "[ --- EdgeCase Tests --- ]" << Reset << endl;
	Bureaucrat edgeCaseBureaucrat("EdgeCase", 2);
	Form edgeCaseForm("EdgeCaseForm", 2, 2);

	cout << Purple << "** Increase Grade **" << Reset << endl;
	edgeCaseBureaucrat.IncreaseGrade();
	cout << "New Grade -> " << edgeCaseBureaucrat.getGrade() << endl;
	cout << Purple << "** Trying to Sign EdgeCaseForm **" << Reset << endl;
	edgeCaseBureaucrat.signForm(edgeCaseForm);

	cout << Purple << "** Decrease Grade **" << Reset << endl;
	edgeCaseBureaucrat.DecreaseGrade();
	cout << "New Grade -> " << edgeCaseBureaucrat.getGrade() << endl;
	cout << Purple << "** Decrease Grade **" << Reset << endl;
	edgeCaseBureaucrat.DecreaseGrade();
	cout << "New Grade -> " << edgeCaseBureaucrat.getGrade() << endl;
	cout << Purple << "** Trying to Sign EdgeCaseForm **" << Reset << endl;
	edgeCaseBureaucrat.signForm(edgeCaseForm);

	return (0);
}