/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:49:17 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/26 10:51:24 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "Wrong Animal";
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original) : Animal(original){
	this->type = original.type;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &rhs){
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	WrongAnimal::makeSound() const{
	std::cout << "ESTOY LOUCOOOO HIHIHIHI ESTOY LOUCO HIHI LOOUCO ESTOY LOUCOOOOOO"  << std::endl;
}