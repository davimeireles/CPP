/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:48:06 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/22 10:22:45 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap parameter constructor called" << std::endl;
}

FragTrap::FragTrap() : ClapTrap(){
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original){
	std::cout << "Copy Constructor Called" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const &rhs){
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return (*this);
}

void	FragTrap::attack(const std::string &target){
	if (this->energyPoints <= 0)
		std::cout << "FragTrap " << this->name << " dont have enough E.P to attack." << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "FragTrap " << this->name << " dont have enough H.P to attack." << std::endl;
	else
		std::cout << "FragTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(){
	std::cout << this->name << " Wants a High FIVE!" << std::endl;
}