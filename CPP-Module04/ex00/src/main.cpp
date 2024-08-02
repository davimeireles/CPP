/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:33 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/26 11:02:40 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/WrongAnimal.hpp"

int main()
{
std::cout << " **** CONSTRUCTOR MENSAGES **** " << std::endl << std::endl;
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const Animal* w = new WrongAnimal();
const Animal* wc = new WrongCat();

std::cout << std::endl;

std::cout << " **** TYPE CLASS **** " << std::endl << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << w->getType() << " " << std::endl;
std::cout << wc->getType() << " " << std::endl;

std::cout << std::endl << std::endl;

std::cout << " **** SOUND OF EACH CLASS **** " << std::endl << std::endl;
i->makeSound();
j->makeSound();
w->makeSound();
wc->makeSound();
meta->makeSound();

std::cout << std::endl << std::endl;

std::cout << " **** DESTRUCTOR MENSAGES **** " << std::endl << std::endl;
delete (meta);
delete (j);
delete (i);
delete (w);
delete (wc);

return 0;
}
