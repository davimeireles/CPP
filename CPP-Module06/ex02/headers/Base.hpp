/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:46:44 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 23:27:03 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

class A;
class B;
class C;

class Base
{	
	public:
		virtual ~Base(void);

};
	Base* generate(void);
	void identify(Base* p);
	void identify(Base& p);

#endif