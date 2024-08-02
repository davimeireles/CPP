/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:49:40 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/26 10:54:51 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	this->type = "WrongCat";
	std::cout << "I'm the wrong cat, boooooooorn..." << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "HAHAHAH LOYCO LOUYCO" << std::endl;
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original){}

WrongCat& WrongCat::operator=(WrongCat const &rhs){
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}
