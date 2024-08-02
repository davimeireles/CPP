/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:22:33 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/02 22:49:32 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScalarConverter.hpp"
#include "../headers/includes.hpp"

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter){
	*this = scalarConverter;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarConverter){
	(void)scalarConverter;
	return *this;
}

void ScalarConverter::convert(const std::string &input)
{
	ConvertToChar(input, static_cast<char>(std::atoi(input.c_str())));
	ConvertToInt(input, static_cast<int>(std::atoi(input.c_str())));
	ConvertToFloat(input, static_cast<float>(std::strtof(input.c_str(), 0)));
	ConvertToDouble(input, static_cast<double>(std::strtod(input.c_str(), 0)));
}

void ScalarConverter::ConvertToChar(const std::string &input, char c)
{
	bool isNumber = true;

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			isNumber = false;
	}
	if (!isNumber || (atoi(input.c_str()) > 255 && atoi(input.c_str()) < 0))
		cout << "char: impossible" << endl;
	else
	{
		if (c < 32 || c > 126)
			cout << "char: Non displayable" << endl;
		else
			cout << "char: " << c << endl;
	}
}

void ScalarConverter::ConvertToInt(const string &input, int i)
{
	char* end;
	bool isNumber = true;
	const char* start = input.c_str();

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[i] != '-')
			isNumber = false;
	}
	if (!isNumber || std::strtol(start, &end, 10) > numeric_limits<int>::max() || std::strtol(start, &end, 10) < numeric_limits<int>::min())
		cout << "int: impossible" << endl;
	else
		cout << "int: " << i << endl;
}

void ScalarConverter::ConvertToFloat(const std::string &input, float f)
{
	bool isNumber = true;

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[i] != '-')
			isNumber = false;
	}
	if (!isNumber)
		std::cout << "float: nanf" << std::endl;
	else
	{
			if (((f * f) / f != f) && f < 0)
				std::cout << "float: -inff" << std::endl;
			else if (((f * f) / f != f) && f > 0)
				std::cout << "float: +inff" << std::endl;
			else
				std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
}

void ScalarConverter::ConvertToDouble(const std::string &input, double d)
{
	bool isNumber = true;

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[i] != '-')
			isNumber = false;
	}
	if (!isNumber)
		std::cout << "double: nan" << std::endl;
	else
	{
		if ((d * d) / d != d && d < 0)
			std::cout << "double: -inf" << std::endl;
		else if ((d * d) / d != d && d > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
}