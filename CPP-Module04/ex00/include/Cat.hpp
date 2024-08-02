/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:22 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/22 14:44:32 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define	CAT_HPP

#include "../include/Animal.hpp"

class Cat : public Animal{

	public:
		Cat();
		~Cat();
		Cat(const Cat &original);
		Cat& operator=(Cat const &rhs);

		void makeSound() const;
};

#endif