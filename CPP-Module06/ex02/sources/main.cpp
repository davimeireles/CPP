/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:32:46 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/24 13:50:10 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/includes.hpp"

int main()
{
	Base *base;
	Base *nulPtr = 0;
	base = generate();

	std::cout << Green << "*** Identify Base With Pointer Paramater ***" << Reset << std::endl;
	identify(base);
	std::endl(std::cout);
	std::cout << Green << "*** Identify Base With Reference Paramater ***" << Reset << std::endl;
	identify(*base);
	std::endl(std::cout);
	std::cout << Green << "*** Identify Base With Null Pointer Paramater ***" << Reset << std::endl;
	identify(nulPtr);

	delete (base);
	delete (nulPtr);
}