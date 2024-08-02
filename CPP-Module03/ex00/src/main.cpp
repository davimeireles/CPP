/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:08:57 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/21 12:57:17 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main( void ){
	ClapTrap trap1;
	ClapTrap trap2("Sudovisudo");

	trap1.setName("Gustavo");
	std::cout << std::endl;
	trap1.attack(trap2.getName());
	trap1.setEnergyPoints(trap1.getEnergyPoints() - 1);
	trap2.takeDamage(trap1.getAttackDamage());
	trap2.beRepaired(0);
	std::cout << std::endl;

	std::cout << std::endl;
	trap2.attack(trap1.getName());
	trap1.takeDamage(trap2.getAttackDamage());
	trap1.beRepaired(0);
	std::cout << std::endl;
}