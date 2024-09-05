/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:15:53 by dmeirele          #+#    #+#             */
/*   Updated: 2024/09/05 10:08:10 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

bool	isValidInput(char* str)
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

bool	isOperator(char* str)
{
	for(int i = 0; str[i]; i++)
	{
		if (str[i] == '-' || str[i] == '+'
			|| str[i] == '/' || str[i] == '*')
			return(true);
	}
	return (false);
}

bool	checkFormat(char* str)
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

bool	isNumber(char* str)
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
	 if (argument.empty())
	 {
		std::cerr << RED << "Error - Argument was empty." << RESET << endl;
		return ;
	 }

	for (size_t i = 0; i < argument.size(); i++)
	{
		if ((argument[i] == ' ' && argument[i + 1] == ' ')
			|| (argument[0] == ' ')
			|| (argument[argument.size() - 1] == ' '))
			{
				std::cerr << RED << "Error - Invalid argument format." << RESET << endl;
				return ;
			}
	}

	int numberCount = 0;
	int operatorCount = 0;

	int		total_tokens = std::count(argument.begin(), argument.end(), ' ') + 1;
	char**	array_ag = new char*[total_tokens];
	char*	argCopy = new char[argument.length() + 1];
	strcpy(argCopy, argument.c_str());

	int i = 0;
	char* token = std::strtok(argCopy, " ");
	while (token && i <= total_tokens)
	{
		array_ag[i] = new char[strlen(token) + 1];
		strcpy(array_ag[i], token);
		token = std::strtok(0, " ");
		i++;
	}

	array_ag[total_tokens] = 0;
	for(int i = 0 ; array_ag[i] ; i++)
		cout << array_ag[i] << endl ;

	if (total_tokens < 3)
	{
		std::cerr << RED << "Error - Too few arguments" << RESET << endl;
		free_pointers(argCopy, array_ag, total_tokens);
		return ;
	}
	
	for(int i = 0; i < total_tokens; i++)
	{
		if (!isValidInput(array_ag[i]))
		{
			std::cerr << RED << "Error - Unexpected argument." << RESET << endl;
			free_pointers(argCopy, array_ag, total_tokens);
			return ;
		}
		if (!checkFormat(array_ag[i]))
		{
			std::cerr << RED << "Error - Invalid number of operators" << RESET << endl;
			free_pointers(argCopy, array_ag, total_tokens);
			return ;
		}
		if (isNumber(array_ag[i]))
			numberCount++;
		if (isOperator(array_ag[i]))
			operatorCount++;
	}
	
	if (operatorCount != (numberCount - 1))
	{
		std::cerr << RED << "Error - Invalid argument content." << RESET << endl;
		free_pointers(argCopy, array_ag, total_tokens);
		return ;
	}

	delete[] argCopy;

	if (!calculate(array_ag))
	{
		for (int j = 0; array_ag[j]; j++)
			delete[] array_ag[j];
		delete[] array_ag;
	}
	else
	{
		for (int j = 0; array_ag[j]; j++)
			delete[] array_ag[j];
		delete[] array_ag;
	}
	return ;
}

bool	calculate(char** array_arg)
{
	std::stack<int> stack_numbers;
	int	first = 0;
	int	second = 0;
	int result = 0;
	int	i = 0;

	while (array_arg[i])
	{
		if (isNumber(array_arg[i]))
			stack_numbers.push(atoi(array_arg[i]));
		else if (isOperator(array_arg[i]))
		{
			first = stack_numbers.top();
			stack_numbers.pop();
			second = stack_numbers.top();
			stack_numbers.pop();

			if (!strcmp(array_arg[i], "-"))
				result = second - first;
			else if (!strcmp(array_arg[i], "+"))
				result = second + first;
			else if (!strcmp(array_arg[i], "*"))
				result = second + first;
			else if (!strcmp(array_arg[i], "/"))
			{
				if (first == 0)
				{
					std::cerr << RED << "Error - Invalid division by zero." << RESET << endl;
					return (false);
				}
				result = second / first;
			}
			stack_numbers.push(result);
		}
		i++;
	}
	cout << "The result is " << CYAN << result << endl;
	return (true);
}

void	free_pointers(char* argCopy, char** array_ag, int i)
{
	for (int j = 0; j <= i; j++)
		delete[] array_ag[j];
	delete[] array_ag;
	delete[] argCopy;
}
