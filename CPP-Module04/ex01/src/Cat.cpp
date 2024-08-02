/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:17 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/28 15:19:37 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal(){
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "You invoke a beautifull cat, the most epic animal in the world." << std::endl;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cats gonna raise again one day, but now they gonna sleep." << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original){
	this->type = original.type;
	this->brain = new Brain(*original.brain);
}

Cat& Cat::operator=(Cat const &rhs){
	if (this != &rhs)
	{
		this->type = rhs.type;
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Miaaaaaaaaaaaaaaaaaaaaaaaaaaaauu" << std::endl;
}
