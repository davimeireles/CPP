/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:15:15 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/10 10:02:22 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
	Zombie *horde;
	int		n = 2147483647;

	horde = zombieHorde(n, "Antonio");
	for(int i = 0; i < n; i++)
		horde[i].announce();
	delete [] (horde);
}