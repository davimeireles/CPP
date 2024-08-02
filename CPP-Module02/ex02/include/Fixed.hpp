#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed( const int fpNumber);
		Fixed( const float floatingPointNumber);
		Fixed( Fixed const & src );
		~Fixed();
		/*
		Comparison Operators
		*/
		bool	operator>(const Fixed &fixed);
		bool	operator<(const Fixed &fixed);
		bool	operator>=(const Fixed &fixed);
		bool	operator<=(const Fixed &fixed); 
		bool	operator==(const Fixed &fixed);
		bool	operator!=(const Fixed &fixed);
		/* 
		Arithmetic Operators 
		*/
		Fixed	operator+(const Fixed &fixed);
		Fixed	operator-(const Fixed &fixed);
		Fixed	operator*(const Fixed &fixed);
		Fixed	operator/(const Fixed &fixed);
		/*
		Increment/Decrement
		*/
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		/*
		Overloaded Member Functions
		*/
		static Fixed&	min(Fixed &num1, Fixed &num2);
		static Fixed&	max(Fixed &num1, Fixed &num2);
		static const Fixed&	min(const Fixed &num1, const Fixed &num2);
		static const Fixed&	max(const Fixed &num1, const Fixed &num2);
		/*
		Assignment Operator
		*/
		Fixed&					operator=(Fixed const &fixed);
		/*
		Methods
		*/
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		static const int	fractionalBits = 8;
		int					fpNumber;
};

/* 
Stream Output Operator
*/
std::ostream &			operator<<( std::ostream & o, Fixed const & i );



#endif