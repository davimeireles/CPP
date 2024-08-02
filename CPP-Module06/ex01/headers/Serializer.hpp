/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:05:22 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/22 15:32:38 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
	Serializer(void);
	Serializer(const Serializer &Serializer);
	virtual ~Serializer(void) = 0;

	Serializer &operator=(const Serializer &rhs);

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};


#endif