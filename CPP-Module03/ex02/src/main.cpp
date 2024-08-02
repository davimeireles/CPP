/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:08:57 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/21 13:08:25 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"


int main( void ){
	ClapTrap trap1;
	ClapTrap trap2("Sudovisudo");
	ScavTrap trap3;
	ScavTrap trap4("Markos");
	FragTrap trap5;
	FragTrap trap6("Claudete");

	trap1.setName("Gustavo");
	trap3.setName("Marcela");
	trap5.setName("Norminette");
	
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

	std::cout << std::endl;
	trap3.attack(trap4.getName());
	trap3.setEnergyPoints(trap3.getEnergyPoints() - 1);
	trap4.takeDamage(trap3.getAttackDamage());

	std::cout << std::endl;

	trap4.attack(trap3.getName());
	trap4.setEnergyPoints(trap4.getEnergyPoints() - 1);
	trap3.takeDamage(trap4.getAttackDamage());

	std::cout << std::endl;

	trap3.guardGate();
	trap4.guardGate();
	std::cout << std::endl;

	trap5.attack(trap6.getName());
	trap5.setEnergyPoints(trap5.getEnergyPoints() - 1);
	trap6.takeDamage(trap5.getAttackDamage());

	std::cout << std::endl;
	trap6.attack(trap5.getName());
	trap6.setEnergyPoints(trap6.getEnergyPoints() - 1);
	trap5.takeDamage(trap6.getAttackDamage());

	std::cout << std::endl;

	trap5.highFivesGuys();
	trap6.highFivesGuys();
	std::cout << std::endl;
}