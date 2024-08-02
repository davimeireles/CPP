/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:40:48 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/22 17:43:29 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


int main()
{
	Base *base;

	base = generate();

	std::cout << "\033[32m" << "*** Identify Base With Pointer Paramater ***" << "\033[0m" << std::endl;
	identify(base);
	std::endl(std::cout);
	std::cout << "\033[32m" << "*** Identify Base With Reference Paramater ***" << "\033[0m" << std::endl;
	identify(*base);
	std::endl(std::cout);

	delete (base);
}