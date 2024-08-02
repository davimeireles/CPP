/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:33 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/28 14:51:09 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/WrongAnimal.hpp"

int main(){

const Animal *listAnimals[10];

std::cout << "/*********** Constructor Mensages ***********/" << std::endl << std::endl;

for (int i = 0; i < 10; i++){
	if (i < 5){
		listAnimals[i] = new Dog();
		std::cout << std::endl;
	}
	else{
		listAnimals[i] = new Cat();
		std::cout << std::endl;
	}
}

std::cout << "/*********** Destructor Mensages ***********/" << std::endl << std::endl;

for (int i = 0; i < 10; i++){
	delete listAnimals[i];
	std::cout << std::endl;
}

return 0;
}
