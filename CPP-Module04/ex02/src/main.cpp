/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:33 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/22 01:06:24 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/WrongAnimal.hpp"

int main(){

std::cout << "/*********** Constructor Mensages ***********/" << std::endl << std::endl;

const Animal *listAnimals[4];
Cat *cat = new Cat();
Cat *cat2 = new Cat();

/* const Animal *meta = new Animal(); */ // now it's an abstract class and i cant instantiate it.

/* It works because we, create an instance of a class that inherits from Animal and implements all of its pure virtual functions */
const Animal* j = new Dog();
std::cout << std::endl;
const Animal* i = new Cat();
std::cout << std::endl;
const Animal* w = new WrongAnimal();
std::cout << std::endl;
const Animal* wc = new WrongCat();
std::cout << std::endl;

for (int i = 0; i < 4; i++){
	if (i < 2){
		listAnimals[i] = new Dog();
		std::cout << std::endl;
	}
	else{
		listAnimals[i] = new Cat();
		std::cout << std::endl;
	}
}

*cat = *cat2;

std::cout << cat2->getType();
std::cout << cat->getType();

std::cout << std::endl;

std::cout << "/*********** Destructor Mensages ***********/" << std::endl << std::endl;

for (int i = 0; i < 4; i++){
	delete listAnimals[i];
	std::cout << std::endl;
}

delete (cat2);
delete (cat);

std::cout << cat2->getType() << std::endl;
std::cout << cat->getType() << std::endl;


delete (j);
std::cout << std::endl;
delete (i);
std::cout << std::endl;
delete (w);
std::cout << std::endl;
delete (wc);
std::cout << std::endl;

return 0;
}
