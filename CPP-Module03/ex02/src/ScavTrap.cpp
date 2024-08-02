/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:35:27 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/22 10:15:01 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap(){
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original){
	std::cout << "Copy Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const &rhs){
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target){
	if (this->energyPoints <= 0)
		std::cout << "ScavTrap " << this->name << " dont have enough E.P to attack." << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "ScavTrap " << this->name << " dont have enough H.P to attack." << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}
