/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:25 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/28 15:16:02 by dmeirele         ###   ########.fr       */
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
		virtual	void makeSound() const;
		Animal&	operator=(Animal const &rhs);

		std::string getType() const;
};

#endif