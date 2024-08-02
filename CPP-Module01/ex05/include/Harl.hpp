/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:41:49 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/09 13:22:20 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#include <map>

class Harl
{

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	
	public:
		void complain( std::string level );
		Harl();
		~Harl();
};

#endif