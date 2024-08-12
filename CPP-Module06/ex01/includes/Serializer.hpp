/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:24:09 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/12 18:24:12 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "includes.hpp"
#include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &Serializer);
		virtual ~Serializer(void) = 0;

		Serializer &operator=(const Serializer &rhs);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif