/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:56:29 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/11 14:38:52 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed( Fixed const & src );
		~Fixed();
		
		Fixed( const int number);
		Fixed( const float floatingPointNumber);
		
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		
		Fixed&		operator=( Fixed const & rhs );

	private:
		static const int	fractionalBits = 8;
		int					fpNumberValue;
	
};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif