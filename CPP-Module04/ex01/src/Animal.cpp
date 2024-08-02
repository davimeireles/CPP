/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:19 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/22 14:40:47 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal(){
	std::cout << "Animal constructor called." << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal destructor called." << std::endl;
}

Animal::Animal(const Animal &original){
	this->type = original.type;
}

Animal&	Animal::operator=(Animal const &rhs){
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string Animal::getType() const{
	return (this->type);
}

void	Animal::makeSound() const{
	std::cout << "Type of the animal not defined, so im gonna make the sound -> PRU PRU PRU PRU rawr"  << std::endl;
}