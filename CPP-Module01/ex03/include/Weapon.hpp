/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:26:19 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/08 18:31:08 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
#define	WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string type);
		Weapon();
		std::string	getType();
		void		setType(std::string type);
		~Weapon();
};

#endif