/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:15:53 by dmeirele          #+#    #+#             */
/*   Updated: 2024/09/04 12:36:12 by dmeirele         ###   ########.fr       */
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

/* 	if (!isNumber(array_ag[0]) || !isNumber(array_ag[1]))
	{
		std::cerr << RED << "Error - Argument 1 and 2 need to be number." << RESET << endl;
		free_pointers(argCopy, array_ag, total_tokens);
		return ;
	}
	
	if (!isOperator(array_ag[2]))
	{
		std::cerr << RED << "Error - Argument 3 need to be some operator." << RESET << endl;
		free_pointers(argCopy, array_ag, total_tokens);
		return ;
	} */
 
	free_pointers(argCopy, array_ag, i);
}

/* void	calculate(std::vector<string> argumentVector)
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
		// cout << numbersStack.top() << endl;
		numbersStack.pop();
	}
} */

/* char** split(string argument)
{
	int		tokenCount = 0;
	char	**splitted;
	char*	token = strtok((char *)(argument.c_str()), " ");

	while (token != nullptr && tokenCount < MAX_TOKENS) {
		strcpy(tokens[tokenCount], token);
		tokenCount++;
		token = strtok(nullptr, " ");
	}

	delete[] inputCopy;
} */

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

void	free_pointers(char* argCopy, char** array_ag, int i)
{
	for (int j = 0; j < i; j++)
		delete[] array_ag[j];
	delete[] array_ag;
	delete[] argCopy;
}
