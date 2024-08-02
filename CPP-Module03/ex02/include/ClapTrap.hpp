/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:50:06 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/22 14:59:30 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{

	protected:
		std::string	name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string	name);
		ClapTrap(const ClapTrap		&ClapTrap);
		virtual ~ClapTrap();

		ClapTrap&	operator=(ClapTrap const &ClapTrap);

		virtual void	attack(const std::string&	target);
		void	takeDamage(unsigned int		amount);
		void	beRepaired(unsigned int		amount);

		std::string	getName();
		int			getHitPoints();
		int			getEnergyPoints();
		int			getAttackDamage();

		void		setName(std::string	name);
		void		setHitPoints(int	hitPoints);
		void		setEnergyPoints(int	energyPoints);
		void		setAttackDamage(int	attackDamage);
};

#endif