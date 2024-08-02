/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:09:10 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/08 14:22:01 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) 
{
	std::string	str =  "HI THIS IS BRAIN";
	std::string *pointerStr = &str;
	std::string& refStr = str;
	

	std::cout << "The memory address of the string variable is	-> " << &str << std::endl;
	std::cout << "The memory address held by stringPTR is		-> " << pointerStr << std::endl;
	std::cout << "The memory address held by stringREF is		-> " << &refStr << std::endl;
	
	std::cout << std::endl;

	std::cout << "The value of the string variable is -> " << str << std::endl;
	std::cout << "The value pointed to by stringPTR is -> " << *pointerStr << std::endl;
	std::cout << "The value pointed to by stringREF is -> " << refStr << std::endl;
}
