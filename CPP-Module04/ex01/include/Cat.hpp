/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:22 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/26 11:39:39 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define	CAT_HPP

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"

class Cat : public Animal{

	private:
		Brain *brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat &original);
		Cat& operator=(Cat const &rhs);

		void makeSound() const;
};

#endif