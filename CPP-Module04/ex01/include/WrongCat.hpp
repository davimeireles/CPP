/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:49:45 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/22 19:18:59 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "../include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &original);
		WrongCat& operator=(WrongCat const &rhs);
};

#endif