/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:44:55 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 12:51:56 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"

int main()
{
	system("clear");
	try
	{
	cout << Orange << "[ --- Normal Constructor --- ]" << Reset << endl;
	Bureaucrat defaultBureaucrat;
	cout << defaultBureaucrat << endl;

	Bureaucrat highGradeBureaucrat("HighGrade", 1);
	cout << highGradeBureaucrat << endl;

	Bureaucrat lowGradeBureaucrat("LowGrade", 150);
	cout << lowGradeBureaucrat << endl << endl;

	cout << Orange << "[ --- Copy Constructor --- ]" << Reset << endl;
	Bureaucrat copyBureaucrat(highGradeBureaucrat);
	cout << copyBureaucrat << endl << endl;

	cout << Orange << "[ --- Assign Operator --- ]" << Reset << endl;
	Bureaucrat assignedBureaucrat = lowGradeBureaucrat;
	cout << assignedBureaucrat << endl << endl;

	cout << Orange << "[ --- Increase and Decrease Grade Test --- ]" << Reset << endl;
	highGradeBureaucrat.IncreaseGrade();
	cout << "Increased grade: " << highGradeBureaucrat.getGrade() << endl;
	lowGradeBureaucrat.DecreaseGrade();
	cout << "Decreased grade: " << lowGradeBureaucrat.getGrade() << endl << endl;

	cout << Orange << "[ --- Testing Exceptions --- ]" << Reset << endl;
	Bureaucrat tooHigh("TooHigh", 0);
	Bureaucrat tooLow("TooLow", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset <<'\n';
	}

return 0;
}