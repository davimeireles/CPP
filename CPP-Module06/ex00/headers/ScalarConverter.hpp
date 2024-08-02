/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:14:32 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/01 04:56:54 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &scalarConverter);
	virtual ~ScalarConverter(void) = 0;

	ScalarConverter &operator=(const ScalarConverter &scalarConverter);

	static void	convert(const std::string &input);

	static void	ConvertToInt(const std::string &input);
	static void	ConvertToChar(const std::string &input);
	static void ConvertToFloat(const std::string &input);
	static void ConvertToDouble(const std::string &input);
};

#endif