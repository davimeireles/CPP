/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:07:15 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/22 10:26:35 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

/* Constructor/Destructor */

ClapTrap::ClapTrap(){
	std::cout << "Clap Trap Default Constructor Called" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string	name){
	std::cout << "Parameter Constructor Called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &ClapTrap){
	std::cout << "Copy Constructor Called" << std::endl;
	this->name = ClapTrap.name;
	this->hitPoints = ClapTrap.hitPoints;
	this->energyPoints = ClapTrap.energyPoints;
	this->attackDamage = ClapTrap.attackDamage;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &ClapTrap){
	if ( this != &ClapTrap)
	{
		this->name = ClapTrap.name;
		this->hitPoints = ClapTrap.hitPoints;
		this->energyPoints = ClapTrap.energyPoints;
		this->attackDamage = ClapTrap.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

/* Getters */

std::string	ClapTrap::getName(){
	return (this->name);
}

int	ClapTrap::getHitPoints(){
	return (this->hitPoints);
}

int	ClapTrap::getEnergyPoints(){
	return (this->energyPoints);
}

int	ClapTrap::getAttackDamage(){
	return (this->attackDamage);
}

/* Setters */

void	ClapTrap::setName(std::string	name){
	this->name = name;
}

void	ClapTrap::setHitPoints(int	hitPoints){
	this->hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int	energyPoints){
	this->energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int	attackDamage){
	this->attackDamage = attackDamage;
}

/* Actions */

void	ClapTrap::attack(const std::string&	target){
	if (this->energyPoints <= 0)
		std::cout << "ClapTrap " << this->name << " dont have enough E.P to attack." << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " dont have enough H.P to attack." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int	amount){
	std::cout << "ClapTrap " << this->name << " loses " << amount << " hitpoints" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int	amount){
	std::cout << "ClapTrap " << this->name << " repaired in " << amount << " hitpoints" << std::endl;
}
