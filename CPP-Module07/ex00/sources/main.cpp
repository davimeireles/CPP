/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:32:00 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/01 05:29:56 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	int a = 10;
	int b = 42;
	std::string name1 = "Davi";
	std::string name2 = "Meireles";
	const char *c1 = "Greg";
	const char *c2 = "Nunan";
	float f1 = 42.42;
	float f2 = 10.10;

	std::cout << "\033[35m" << "--- Variables ---" << "\033[0m" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "name1: " << name1 << std::endl;
	std::cout << "name2: " << name2 << std::endl;
	std::cout << "c1: " << c1 << std::endl;
	std::cout << "c2: " << c2 << std::endl;
	std::cout << "f1: " << f1 << std::endl;
	std::cout << "f2: " << f2 << std::endl << std::endl;

	std::cout << "\033[32m" << "--- Testing swap ---" << "\033[0m" << std::endl << std::endl;

	std::cout << "\033[31m" << "With Integers" << "\033[0m" << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	swap(a, b);
	std::cout << "a: " << a << " b: " << b << std::endl << std::endl;
	
	std::cout << "\033[31m" << "With String" << "\033[0m" << std::endl;
	std::cout << "a: " << name1 << " b: " << name2 << std::endl;
	swap(name1, name2);
	std::cout << "a: " << name1 << " b: " << name2 << std::endl << std::endl;
 
	std::cout << "\033[31m" << "With Char*" << "\033[0m" << std::endl;
	std::cout << "a: " << c1 << " b: " << c2 << std::endl;
	swap(c1, c2);
	std::cout << "a: " << c1 << " b: " << c2 << std::endl << std::endl;

	std::cout << "\033[31m" << "With Float" << "\033[0m" << std::endl;
	std::cout << "a: " << f1 << " b: " << f2 << std::endl;
	swap(f1, f2);
	std::cout << "a: " << f1 << " b: " << f2 << std::endl << std::endl;
	
	std::cout << "\033[32m" << "--- Testing min ---" << "\033[0m" << std::endl;

	std::cout << "\033[31m" << "With Integers" << "\033[0m" << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl << std::endl;
	
	std::cout << "\033[31m" << "With String" << "\033[0m" << std::endl;
	std::cout << "min( name1, name2 ) = " << ::min( name1, name2 ) << std::endl << std::endl;

	std::cout << "\033[31m" << "With Char*" << "\033[0m" << std::endl;
	std::cout << "min( c1, c2 ) = " << ::min( c1, c2 ) << std::endl << std::endl;
	
	std::cout << "\033[31m" << "With Float" << "\033[0m" << std::endl;
	std::cout << "min( f1, f2 ) = " << ::min( f1, f2 ) << std::endl << std::endl;

	std::cout << "\033[32m" << "--- Testing max ---" << "\033[0m" << std::endl;
	
	std::cout << "\033[31m" << "With Integers" << "\033[0m" << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;

	std::cout << "\033[31m" << "With String" << "\033[0m" << std::endl;
	std::cout << "max( name1, name2 ) = " << ::max( name1, name2 ) << std::endl << std::endl;
	
	std::cout << "\033[31m" << "With Char*" << "\033[0m" << std::endl;
	std::cout << "max( c1, c2 ) = " << ::max( c1, c2 ) << std::endl << std::endl;

	std::cout << "\033[31m" << "With Float" << "\033[0m" << std::endl;
	std::cout << "max( f1, f2 ) = " << ::max( f1, f2 ) << std::endl << std::endl;

	std::cout << "\033[33m" << "--- Subject Main Test ---" << "\033[0m" << std::endl << std::endl;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return (0);
}
