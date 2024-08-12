/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:34:30 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/12 18:34:35 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base(void) {}

Base* generate(void)
{
	static bool seeded = false;
	int dice;

	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}
	dice = std::rand() % 3;
	if (dice == 0)
		return (new A());
	else if (dice % 2 == 0)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identify A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identify B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identify C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identify A" << std::endl;
		return ;
	}
	catch (const std::exception& e){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identify B" << std::endl;
		return ;
	}
	catch (const std::exception& e){}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identify C" << std::endl;
		return ;
	}
	catch(const std::exception& e){std::cout << "Identify Unknown" << std::endl;}

}