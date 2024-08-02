/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:43:09 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/09 14:06:46 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main(int argc, char **argv) 
{
	Harl	robot;

	if (argc == 2)
		robot.complain(argv[1]);
	else if (argc > 2)
		std::cout << "Harl only works with 1 input, i know its boring but please "
					"dont burnout the poor robot. Thank you (=" << std::endl;
	else
		std::cout << "Harl is like C, you need to say exactly what he need to do, "
					"otherwise he will do nothing. Thank you =)" << std::endl;
}
