/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:17 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/22 14:46:29 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal(){
	this->type = "Cat";
	std::cout << "You invoke a beautifull cat, the most epic animal in the world." << std::endl;
}

Cat::~Cat(){
	std::cout << "Cats gonna raise again one day, but now they gonna sleep." << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original){}

Cat& Cat::operator=(Cat const &rhs){
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Miaaaaaaaaaaaaaaaaaaaaaaaaaaaauu" << std::endl;
}
