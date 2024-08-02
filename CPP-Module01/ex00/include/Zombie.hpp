/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:50:06 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/08 12:50:23 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <iomanip>

class Zombie
{
	private:
		std::string	name;
		
	public:
		Zombie	( void );
		Zombie	( std::string name );
		~Zombie	( void );

		void	announce( void );
};

#endif