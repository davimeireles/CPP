/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:14:32 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 22:36:43 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "includes.hpp"

class ScalarConverter
{
	public:
		static void	convert(const string &input);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &scalarConverter);
		virtual ~ScalarConverter(void) = 0;

		ScalarConverter &operator=(const ScalarConverter &scalarConverter);

		static void ConvertToChar(const string &input, char c);
		static void ConvertToInt(const string &input, int i);
		static void ConvertToFloat(const string &input, float f);
		static void ConvertToDouble(const string &input, double d);
};

#endif