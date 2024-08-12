/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:30:17 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/12 18:32:14 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include "includes.hpp"

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