/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:52:21 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/11 14:52:22 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
	this->fpNumber = 0;
}

Fixed::Fixed( const Fixed &src ){
	// std::cout << "Copy constructor called" << std::endl;
	this->fpNumber = src.getRawBits();
}

Fixed::Fixed( const int number ){
	// std::cout << "Int constructor called" << std::endl;
	this->fpNumber = number << fractionalBits;
}

Fixed::Fixed( const float floatingPointNumber){
	// std::cout << "Float constructor called" << std::endl;
	this->fpNumber = roundf(floatingPointNumber * (1 << fractionalBits));
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const &fixed){
	// std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &fixed )
		this->fpNumber = fixed.getRawBits();
	return (*this);
}

std::ostream &			operator<<( std::ostream &output, Fixed const &input){
	output << input.toFloat();
	return (output);
}

/*
Comparison Operators
*/

bool	Fixed::operator>(const Fixed &fixed){
	if (this->fpNumber > fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &fixed){
	if (this->fpNumber < fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &fixed){
	if (this->fpNumber >= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &fixed){
	if (this->fpNumber <= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &fixed){
	if (this->fpNumber == fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &fixed){
	if (this->fpNumber != fixed.getRawBits())
		return (true);
	return (false);
}

/* 
Arithmetic Operators 
*/

Fixed	Fixed::operator+(const Fixed &fixed){
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fixed){
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed){
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fixed){
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

/*
Increment/Decrement
*/

Fixed	&Fixed::operator++(){
	++fpNumber;
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed	helper(*this);
	operator++();
	return (helper);
}

Fixed	&Fixed::operator--(){
	--fpNumber;
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed	helper(*this);
	operator--();
	return (helper);
}

/*
Overloaded Member Functions
*/
Fixed&	Fixed::min(Fixed &num1, Fixed &num2){
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	return (num2);
}

const Fixed&	Fixed::min(const Fixed &num1, const Fixed &num2){
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	return (num2);
}

Fixed& Fixed::max(Fixed &num1, Fixed &num2){
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	return (num2);
}

const Fixed&	Fixed::max(const Fixed &num1, const Fixed &num2){
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	return (num2);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int		Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fpNumber);
}

void	Fixed::setRawBits( int const raw ){
	this->fpNumber = raw;
}

int Fixed::toInt() const {
	return (static_cast<int>(roundf(toFloat())));
}
/* To convert a fixed-point value to a floating-point value, you typically divide the fixed-point value by a scale factor.
 The scale factor is usually  a power of 2, such as 2^8, 2^16, etc.,
  depending on the number of fractional bits in your fixed-point representation. */
float Fixed::toFloat() const {
	return (static_cast<float>(getRawBits()) / (1 << fractionalBits));
}