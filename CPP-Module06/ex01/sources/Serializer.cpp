/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:24:33 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/12 18:24:49 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &Serializer) {*this = Serializer;}

Serializer::~Serializer(void) {}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(new Data(*ptr));
	return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}