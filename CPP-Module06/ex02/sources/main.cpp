/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:32:46 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/12 18:34:56 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

int main()
{
	Base *base;
	Base *nulPtr = 0;
	base = generate();

	std::cout << "\033[32m" << "*** Identify Base With Pointer Paramater ***" << "\033[0m" << std::endl;
	identify(base);
	std::endl(std::cout);
	std::cout << "\033[32m" << "*** Identify Base With Reference Paramater ***" << "\033[0m" << std::endl;
	identify(*base);
	std::endl(std::cout);
	std::cout << "\033[32m" << "*** Identify Base With Null Pointer Paramater ***" << "\033[0m" << std::endl;
	identify(nulPtr);

	delete (base);
	delete (nulPtr);
}