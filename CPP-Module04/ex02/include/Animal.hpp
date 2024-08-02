/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:25 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/01 11:02:17 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP

#include <iostream>

class Animal{

	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal &original);
		virtual	~Animal();

		Animal&	operator=(Animal const &rhs);
		
		virtual	void makeSound() const = 0;

		std::string getType() const;
};

#endif