/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:21 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/22 14:46:58 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal(){
	this->type = "Dog";
	std::cout << "The best friend of a human just BORN." << std::endl;
}

Dog::~Dog(){
	std::cout << "The beach was so good but the doog needs to sleep now." << std::endl;
}

Dog::Dog(const Dog &original) : Animal(original){}

Dog& Dog::operator=(Dog const &rhs){
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Au Au Au Au Au grrrrrrrrr" << std::endl;
}