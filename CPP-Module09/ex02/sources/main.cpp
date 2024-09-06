/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:21:05 by dmeirele          #+#    #+#             */
/*   Updated: 2024/09/06 10:25:43 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc <= 2)
		std::cerr << RED << "Error\nUsage: ./PmergeMe 4 2 7 5 1" << RESET << endl;
	else
		PmergeMe(argv);
}