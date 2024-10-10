/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:22:00 by dmeirele          #+#    #+#             */
/*   Updated: 2024/10/01 17:31:17 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

bool	isNumber(string str)
{
	if (std::isdigit(static_cast<int>(str[0])))
		return (true);
	if ((str[0] != '-' && str[0] != '+'))
		return (false);
	if (str[1] && std::isdigit(str[1]))
		return (true);
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
		if (!str[i])
			break;
		i++;
	}
	if (countOperators > 1)
		return (false);
	return (true);
}

void	PmergeMe(char** argv)
{
	std::vector<int> num_vector;
	std::list<int> num_list;

	if (!parsing(argv))
	{
		std::cerr << RED << "Error\nInvalid Input." << RESET << endl;
		return;
	}

	for (int i = 1; argv[i]; i++)
	{
		num_vector.push_back(std::atoi(argv[i]));
		num_list.push_back(std::atoi(argv[i]));
	}

	cout << "Before: ";
	for (size_t i = 0; i < num_vector.size(); i++) {
		cout << RED << num_vector[i] << " ";
	}
	cout << RESET << endl;

	clock_t start_vector = clock();
	fordJohnsonSortVector(num_vector);
//	mergeInsertionSortVector(num_vector, 0, num_vector.size() - 1);
	clock_t end_vector = clock();

	cout << "After:  ";
	for (size_t i = 0; i < num_vector.size(); i++)
		cout << GREEN << num_vector[i] << " ";
	cout << RESET << endl;

	double time_taken_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC * 1000000.0;
	cout << CYAN << "Time to process a range of " << num_vector.size() << " elements with std::vector : " << time_taken_vector << " us" << RESET <<endl;

	cout << endl;

	cout << "Before: ";
	for (std::list<int>::const_iterator it = num_list.begin(); it != num_list.end(); ++it)
		cout << RED << *it << " ";
	cout << RESET << endl;

	clock_t start_list = clock();
	fordJohnsonSortList(num_list);
	clock_t end_list = clock();

	cout << "After:  ";
	for (std::list<int>::const_iterator it = num_list.begin(); it != num_list.end(); ++it)
		cout << GREEN << *it << " ";
	cout << RESET << endl;

	double time_taken_list = double(end_list - start_list) / CLOCKS_PER_SEC * 1000000.0;
	cout << CYAN << "Time to process a range of " << num_list.size() << " elements with std::list : " << time_taken_list << " us" << RESET << endl;
}

bool	parsing(char** argv)
{
	double	num;

	string for_validation;

	for (int i = 1; argv[i]; i++)
	{
		for_validation = argv[i];
		if (!checkFormat(argv[i]))
			return (false);
		if (!isNumber(argv[i]))
			return (false);
		for (size_t i = 0; i < for_validation.size(); i++)
		{
			if (!std::isdigit(for_validation[i]))
				return (false);
		}
		num = std::strtod(argv[i], 0);
		if (num < 0 || num > INT_MAX)
			return (false);
	}

	int i = 1;
	int j;

	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (std::atoi(argv[i]) == std::atoi(argv[j]))
				return (false);
			j++;
		}
		i++;
	}

	i = 1;
	bool flag = true;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (std::atoi(argv[i]) < std::atoi(argv[j]))
				j++;
			else
			{
				flag = false;
				j++;
			}
		}
		i++;
	}

	if (flag)
	{
		cout << CYAN << "Already Sorted." << RESET << endl;
		return (false);
	}
	return (true);
}

void fordJohnsonSortVector(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;

	// Fase 1: Comparação de pares
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		if (vec[i] > vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
	}

	// Fase 2: Ordenação recursiva dos elementos maiores
	std::vector<int> larger;
	std::vector<int> smaller;
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		smaller.push_back(vec[i]);
		if (i + 1 < vec.size())
			larger.push_back(vec[i + 1]);
	}

	fordJohnsonSortVector(larger);

	// Fase 3: Inserção dos elementos
	std::vector<int> result = larger;

	// Inserir elementos menores
	for (size_t i = 0; i < smaller.size(); ++i)
		binaryInsertVector(result, 0, result.size(), smaller[i]);

	vec = result;
}

void binaryInsertVector(std::vector<int>& vec, int start, int end, int value)
{
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		if (vec[mid] < value)
			start = mid + 1;
		else
			end = mid;
	}
	vec.insert(vec.begin() + start, value);
}

void binaryInsertList(std::list<int>& lst, int value)
{
	std::list<int>::iterator it = lst.begin();
	while (it != lst.end() && *it < value)
		++it;
	lst.insert(it, value);
}

void fordJohnsonSortList(std::list<int>& lst)
{
	if (lst.size() <= 1)
		return;

	// Fase 1: Comparação de pares
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator next;
	while (it != lst.end())
	{
		next = it;
		++next;
		if (next != lst.end())
		{
			if (*it > *next)
			{
				int temp = *it;
				*it = *next;
				*next = temp;
			}
			++it;
		}
		++it;
	}

	// Fase 2: Ordenação recursiva dos elementos maiores
	std::list<int> larger;
	std::list<int> smaller;
	it = lst.begin();
	while (it != lst.end())
	{
		smaller.push_back(*it);
		++it;
		if (it != lst.end())
		{
			larger.push_back(*it);
			++it;
		}
	}

	fordJohnsonSortList(larger);

	// Fase 3: Inserção dos elementos
	std::list<int> result = larger;

	// Inserir elementos menores
	for (std::list<int>::iterator it = smaller.begin(); it != smaller.end(); ++it)
		binaryInsertList(result, *it);

	lst = result;
}