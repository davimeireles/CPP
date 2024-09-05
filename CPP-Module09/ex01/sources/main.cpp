/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:13:27 by dmeirele          #+#    #+#             */
/*   Updated: 2024/09/03 18:59:29 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		std::cerr << RED << "Error\nUsage: ./RPN \"expression\"" << RESET << endl;
	else
		parsing(argv[1]);
}