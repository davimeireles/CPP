/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:08:57 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/08 12:55:42 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );

int main(int argc, char **argv) 
{

	if (argc == 1)
	{
		Zombie	*zombie = new Zombie();
		zombie->announce();
		delete(zombie);
	}
	else
	{
		int i = 1;
		Zombie	*myZombie;
		while (argv[i])
		{
			myZombie = newZombie(argv[i]);
			myZombie->announce();
			delete (myZombie);
			i++;
		}
	}	
	randomChump("Tio Paulo");
}
