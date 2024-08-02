/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:27:15 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/28 15:22:50 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain(){
	std::cout << "Oh my god now i have a BRAIN!" << std::endl;
}

Brain::Brain(const Brain &original){
	for (int i = 0; i < 100; i++)
		this->ideas[i] = original.ideas[i];
}

Brain::~Brain(){
	std::cout << "OH NO now im a no-brainer" << std::endl;
}

Brain& Brain::operator=(Brain const &rhs){
	if (this != &rhs)
	{	
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}
