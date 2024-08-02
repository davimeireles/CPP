/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:15:29 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/10 12:18:05 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fpNumberValue;
		static const int	fracBits = 8;

	public:
		Fixed();
		Fixed(Fixed const& copy);
		Fixed &operator=(Fixed const& original);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};


#endif