/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:24 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/26 11:38:35 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define	DOG_HPP

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"

class Dog : public Animal{

	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog& original);
		Dog& operator=(Dog const &rhs);

		void makeSound() const;
};

#endif