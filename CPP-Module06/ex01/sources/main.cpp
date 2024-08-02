/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:17:58 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 23:11:55 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Serializer.hpp"

int main()
{
	Data info = {"Gregorio", 5};
	uintptr_t address = Serializer::serialize(&info);
	Data* ptr = Serializer::deserialize(address);

	std::cout << "Original data: " << info.name << " has " << info.age << " years old." << std::endl;
	std::cout << "Memory address: " << &info << std::endl << std::endl;
	
	std::cout << "Serialized data: " << address << std::endl;
	std::cout << "Memory address: " << &address << std::endl << std::endl;

	std::cout << "Deserialized data: " << ptr->name << " has " << ptr->age << " years old." << std::endl;
	std::cout << "Memory address: " << ptr << std::endl << std::endl;
}