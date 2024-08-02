/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:22:33 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/20 20:40:46 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
	ConvertToChar(input);
	ConvertToInt(input);
	ConvertToFloat(input);
	ConvertToDouble(input);
}

void ScalarConverter::ConvertToChar(const std::string &input)
{
	int result;
	bool isNumber = true;

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			isNumber = false;
	}
	if (!isNumber || (atoi(input.c_str()) > 255 && atoi(input.c_str()) < 0))
		std::cout << "char: impossible" << std::endl;
	else
	{
		result = atoi(input.c_str());
		if ((char) result < 32 || (char) result > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << (char) result << std::endl;
	}
}

void ScalarConverter::ConvertToInt(const std::string &input)
{
	char* end;
	int result;
	bool isNumber = true;
	const char* start = input.c_str();

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[i] != '-')
			isNumber = false;
	}
	if (!isNumber || strtol(start, &end, 10) > std::numeric_limits<int>::max() || strtol(start, &end, 10) < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
	{
		result = atoi(input.c_str());
		std::cout << "int: " << result << std::endl;
	}
}

void ScalarConverter::ConvertToFloat(const std::string &input)
{
	float result;
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
			result = atof(input.c_str());
			if (((result * result) / result != result) && result < 0)
				std::cout << "float: -inff" << std::endl;
			else if (((result * result) / result != result) && result > 0)
				std::cout << "float: +inff" << std::endl;
			else
				std::cout << "float: " << std::fixed << std::setprecision(1) << result << "f" << std::endl;
	}
}

void ScalarConverter::ConvertToDouble(const std::string &input)
{
	char* end;
	double result;
	bool isNumber = true;
	const char* start= input.c_str();

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[i] != '-')
			isNumber = false;
	}
	if (!isNumber)
		std::cout << "double: nan" << std::endl;
	else
	{
		result = strtod(start, &end);
		if ((result * result) / result != result && result < 0)
			std::cout << "double: -inf" << std::endl;
		else if ((result * result) / result != result && result > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << result << std::endl;
	}
}