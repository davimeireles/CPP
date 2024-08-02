/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:33:23 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/08 20:07:24 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

std::string HumanA::getName()
{
	return (this->name);
}

void	HumanA::setName(std::string name)
{
	this->name = name;
}

HumanA::~HumanA(){};

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon)
{
	this->setName(name);
}
