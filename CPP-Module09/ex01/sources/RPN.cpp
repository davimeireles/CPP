/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:15:53 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/29 09:15:53 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

bool	isValidInput(string str)
{
	for(size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != '-' && str[i] != '+'
			&& str[i] != '/' && str[i] != '*'
			&& !std::isdigit(str[i]))
			return(false);
	}
	return (true);
}

bool	isOperator(string str)
{
	for(size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+'
			|| str[i] == '/' || str[i] == '*')
			return(true);
	}
	return (false);
}

bool	checkFormat(string str)
{
	int	i = 0;
	int countOperators = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+'
			|| str[i] == '/' || str[i] == '*')
			countOperators++;
		if (std::isdigit(str[i]))
		{
			while (str[i])
			{
				if (str[i] == '-' || str[i] == '+'
					|| str[i] == '/' || str[i] == '*')
					return (false);
				i++;
			}
		}
		i++;
	}
	if (countOperators > 1)
		return (false);
	return (true);
}

bool	isNumber(string str)
{
	if (std::isdigit(str[0]))
		return (true);
	if ((str[0] == '-' || str[0] == '+'))
	{
		if (str[1] && std::isdigit(str[1]))
			return (true);
	}
	return (false);
}

void	parsing(string argument)
{
	std::vector<string> argumentVector;
	int numberCount = 0;
	int operatorCount = 0;
	argumentVector = splitString(argument, ' ');

	for (size_t i = 0; i < argument.size(); i++)
	{
		if (argument[i] == ' ' && argument[i + 1] == ' ')
			p_error("Error - Invalid argument format.");
	}
	if (argumentVector.empty())
		p_error("Error - Argument was empty.");
	if (argumentVector.size() < 3)
		p_error("Error - Too few arguments.");
	for(size_t i = 0; i < argumentVector.size(); i++)
	{
		if (!isValidInput(argumentVector[i]))
			p_error("Error - Unexpected argument.");
		if (!checkFormat(argumentVector[i]))
			p_error("Error - Invalid number of operators");
		if (isNumber(argumentVector[i]))
			numberCount++;
		if (isOperator(argumentVector[i]))
			operatorCount++;
	}
	if (operatorCount != (numberCount - 1))
		p_error("Error - Invalid argument content.");
	if (!isNumber(argumentVector[0]) || !isNumber(argumentVector[1]))
		p_error("Error - Argument 1 and 2 need to be number.");
	if (!isOperator(argumentVector[2]))
		p_error("Error - Argument 3 need to be some operator.");

/*	for (size_t i = 0; i < argumentVector.size(); i++)
		cout << argumentVector[i] << endl;*/

	calculate(argumentVector);
}

void	calculate(std::vector<string> argumentVector)
{
	std::stack<double> numbersStack;
	double				value = 0;

	for (size_t i = 0; i < argumentVector.size(); i++)
	{
		if (isNumber(argumentVector[i]))
		{
			value = std::strtod(argumentVector[i].c_str(), 0);
			numbersStack.push(value);
		}
	}
	while (!numbersStack.empty())
	{
		cout << numbersStack.top() << endl;
		numbersStack.pop();
	}
}

std::vector<string> splitString(string& argument, char delimiter)
{
	string token;
	std::vector<string> tokens;
	std::istringstream tokenStream(argument);

	while (std::getline(tokenStream, token, delimiter))
	{
		if (!token.empty())
			tokens.push_back(token);
	}
	return (tokens);
}

void trim(string &str)
{
	int end = str.size() - 1;
	while(end > 0 && isspace(str[end]))
		end--;
	str.erase(end + 1);
	unsigned int i = 0;
	while(i < str.size() && isspace(str[i]))
		i++;
	str.erase(0, i);
}

void	p_error(string error)
{
	std::cerr << RED << error << RESET << endl;
	exit(EXIT_FAILURE);
}

