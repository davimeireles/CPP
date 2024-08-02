/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:51:17 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/11 14:34:57 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"


Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->fpNumberValue = 0;
}

Fixed::Fixed(Fixed const& copy){
	std::cout << "Copy constructor called" << std::endl;
	this->fpNumberValue = copy.getRawBits();
}

Fixed& Fixed::operator=(Fixed const& original){
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &original)
		this->fpNumberValue = original.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fpNumberValue);
}

void	Fixed::setRawBits( int const raw ){this->fpNumberValue = raw;}

