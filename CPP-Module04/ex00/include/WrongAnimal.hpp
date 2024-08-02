/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:49:47 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/28 15:10:18 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include "../include/Animal.hpp"

class WrongAnimal : public Animal{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &original);
		virtual	~WrongAnimal();
		void makeSound() const;
		WrongAnimal&	operator=(WrongAnimal const &rhs);
};

#endif