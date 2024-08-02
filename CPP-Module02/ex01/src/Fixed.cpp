/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:52:15 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/11 14:52:16 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->fpNumberValue = 0;
}

Fixed::Fixed( const Fixed & src ){
	std::cout << "Copy constructor called" << std::endl;
	this->fpNumberValue = src.fpNumberValue;
}

Fixed::Fixed( const int number ){
	std::cout << "Int constructor called" << std::endl;
	this->fpNumberValue = number << fractionalBits;
}

Fixed::Fixed( const float floatingPointNumber){
	std::cout << "Float constructor called" << std::endl;
	this->fpNumberValue = roundf(floatingPointNumber * (1 << fractionalBits));
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const &fixed ){
	if ( this != &fixed )
		this->fpNumberValue = fixed.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i ){
	o << i.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int Fixed::toInt() const {
	return (static_cast<int>(roundf(toFloat())));
}

int		Fixed::getRawBits( void ) const {
	return (this->fpNumberValue);
}

/* To convert a fixed-point value to a floating-point value, you typically divide the fixed-point value by a scale factor.
 The scale factor is usually  a power of 2, such as 2^8, 2^16, etc.,
  depending on the number of fractional bits in your fixed-point representation. */
float Fixed::toFloat() const {
	return (static_cast<float>(getRawBits()) / (1 << fractionalBits));
}
