/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:26:02 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/08 19:14:04 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANA_HPP
#define	HUMANA_HPP

#include "../include/Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon&		weapon;
	
	public:
		HumanA(std::string name, Weapon& weapon);
		std::string getName();
		void		setName(std::string name);
		void		attack()
		{
			std::cout << this->getName();
			std::cout << " attacks with their ";
			std::cout << weapon.getType();
			std::cout << std::endl;
		}
		~HumanA();
};

#endif