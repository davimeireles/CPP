/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:41:39 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/09 13:39:13 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"


void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::complain( std::string level )
{

	for (unsigned long i = 0; i < level.size(); i++)
		level[i] = toupper(level[i]);

	void	(Harl::*functionList[4])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string	levels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; functionList[i]; i++)
	{
		if (levels[i] == level)
			(this->*functionList[i])();
	}
}









































/* void Harl::complain( std::string level, void (Harl::*Action)())
{
	int	opt;

	if (level == "debug")
		opt = DEBUG;
	else if (level == "info")
		opt = INFO;
	else if (level == "warning")
		opt = WARNING;
	else if (level == "error")
		opt = ERROR;
	else
		opt = UNKNOWN;
	
	switch (opt)
	{
		case DEBUG:
		{
			
			break;
		}
		case INFO:
		{
			info;
			break;
		}
		case WARNING:
		{
			warning;
			break;
		}
		case ERROR:
		{
			error;
			break;
		}
		case UNKNOWN:
		{
			std::cout << "Harl 2.0 dont have that feature. You can use [DEBUG][INFO][WARNING][ERROR]." << std::endl;
			break;
		}
	}
} */

Harl::Harl(){}

Harl::~Harl(){}