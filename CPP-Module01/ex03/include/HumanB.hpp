/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:25:31 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/08 20:01:24 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANB_HPP
#define	HUMANB_HPP

#include "../include/Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon*		weapon;
	
	public:
		HumanB(std::string name);
		std::string getName();
		void		setName(std::string name);
		void		setWeapon(Weapon& weapon);
		void		attack()
		{
			if (weapon)
			{
			std::cout << this->getName();
			std::cout << " attacks with their ";
			std::cout << weapon->getType();
			std::cout << std::endl;
			}
			else
				std::cout << "man you dont have a weapon, so you died by the attack of a wild bear." << std::endl;
		}
		~HumanB();
};

#endif