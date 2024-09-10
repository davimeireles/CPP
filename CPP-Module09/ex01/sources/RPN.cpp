/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:15:53 by dmeirele          #+#    #+#             */
/*   Updated: 2024/09/05 22:34:03 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

bool	checkInput(string str)
{
	for(int i = 0; str[i]; i++)
	{
		if (str[i] != '-' && str[i] != '+'
			&& str[i] != '/' && str[i] != '*'
			&& !std::isdigit(str[i]))
			return(false);
	}
	return (true);
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
		if (!str[i])
			break;
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

bool	checkWhiteSpaces(string str)
{
	for (string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isspace(static_cast<unsigned char>(*it)))
			return (false);
	}
	return (true);
}

void	parsing(string argument)
{
	std::istringstream str(argument);
	std::stack<int> stack_numbers;
	string	token;
	int count_numbers = 0;
	int	count_operators = 0;
	int number = 0;

	if (argument.empty() || checkWhiteSpaces(argument))
	{
		std::cerr << RED << "Error\nInvalid Input." << RESET << endl;
		return;
	}

	while (str >> token)
	{
		if (!checkInput(token) || !checkFormat(token)) {
			std::cerr << RED << "Error\nInvalid Input." << RESET << endl;
			return;
		}
		if (isNumber(token))
		{
			number = std::atoi(token.c_str());
			if (number >= 10)
			{
				std::cerr << RED << "Error\nInvalid Input." << RESET << endl;
				return;
			}
			stack_numbers.push(std::atoi(token.c_str()));
			count_numbers++;
		}
		else
		{
			count_operators++;
			if (!calculate(stack_numbers, token))
			{
				std::cerr << RED << "Error\nInvalid Input." << RESET << endl;
				return;
			}
		}
	}
	if ((count_numbers - 1) != count_operators)
	{
		std::cerr << RED << "Error\nInvalid Input." << RESET << endl;
		return;
	}
	cout << "Result = " << CYAN << stack_numbers.top() << RESET << endl;
}

bool	calculate(std::stack<int>& stack_numbers, string op)
{

	int	first = stack_numbers.top();
	stack_numbers.pop();
	int second = stack_numbers.top();
	stack_numbers.pop();

	int result;

	if (op == "+")
		result = second + first;
	else if (op == "-")
		result = second - first;
	else if (op == "*")
		result = second * first;
	else if (op == "/")
	{
		if (first == 0)
			return (false);
		result = second / first;
	}

	stack_numbers.push(result);
	return (true);
}