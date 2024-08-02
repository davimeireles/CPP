/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:41:07 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/08 13:51:25 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *newZombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		newZombies[i].zombieSetName(name);
	return (newZombies);
}