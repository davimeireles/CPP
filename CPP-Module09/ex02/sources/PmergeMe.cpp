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
	mergeInsertionSortVector(num_vector, 0, num_vector.size() - 1);
	clock_t end_vector = clock();

	std::cout << "After:  ";
	for (size_t i = 0; i < num_vector.size(); i++)
		std::cout << GREEN << num_vector[i] << " ";
	std::cout << RESET << std::endl;

	double time_taken_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC * 1000000.0;
	cout << CYAN << "Time to process a range of " << num_vector.size() << " elements with std::vector : " << time_taken_vector << " us" << RESET <<endl;

	cout << endl;

	std::cout << "Before: ";
	for (std::list<int>::const_iterator it = num_list.begin(); it != num_list.end(); ++it)
		std::cout << RED << *it << " ";
	std::cout << RESET << std::endl;

	clock_t start_list = clock();
	mergeInsertionSortList(num_list);
	clock_t end_list = clock();

	std::cout << "After:  ";
	for (std::list<int>::const_iterator it = num_list.begin(); it != num_list.end(); ++it)
		std::cout << GREEN << *it << " ";
	std::cout << RESET << std::endl;

	double time_taken_list = double(end_list - start_list) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << CYAN << "Time to process a range of " << num_list.size() << " elements with std::list : " << time_taken_list << " us" << RESET << std::endl;
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

void	fordJohnsonSort(std::vector<int>& vec)
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
	std::vector<int>	larger;
	for (size_t i = 1; i < vec.size(); i += 2)
		larger.push_back(vec[i]);

	if (vec.size() % 2 == 1)
		larger.push_back(vec.back());

	fordJohnsonSort(larger);

	// Fase 3: Inserção dos elementos menores
	vec.clear();
	vec.push_back(larger[0]);

	std::vector<size_t> insertSequence = {1};
	size_t power = 2;
	while (power < larger.size()) {
		for (size_t i = power - 1; i < std::min(power * 2 - 1, larger.size()); ++i) {
			insertSequence.push_back(i);
		}
		power *= 2;
	}

	for (size_t index : insertSequence) {
		if (index < larger.size()) {
			binaryInsert(vec, 0, vec.size(), larger[index]);
		}
	}

	// Inserir os elementos menores restantes
	for (size_t i = 0; i < larger.size(); i++) {
		if (std::find(insertSequence.begin(), insertSequence.end(), i) == insertSequence.end()) {
			binaryInsert(vec, 0, vec.size(), larger[i]);
		}
	}
}

void insertionSortVector(std::vector<int>& num_vector, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = num_vector[i];
		int j = i - 1;
		while (j >= left && num_vector[j] > key)
		{
			num_vector[j + 1] = num_vector[j];
			j--;
		}
		num_vector[j + 1] = key;
	}
}

void mergeVector(std::vector<int>& num_vector, int left, int mid, int right)
{
	std::vector<int> temp(right - left + 1);
	int	i = left;
	int	j = mid +  1;
	int	k = 0;

	while (i <= mid && j <= right)
	{
		if (num_vector[i] <= num_vector[j])
			temp[k++] = num_vector[i++];
		else
			temp[k++] = num_vector[j++];
	}

	while (i <= mid)
		temp[k++] = num_vector[i++];

	while (j <= right)
		temp[k++] = num_vector[j++];

	for (int p = 0; p < k; p++)
		num_vector[left + p] = temp[p];
}

void mergeInsertionSortVector(std::vector<int>& num_vector, int left, int right)
{
	if (right - left <= 10) {
		insertionSortVector(num_vector, left, right);
		return;
	}

	int mid = left + (right - left) / 2;
	mergeInsertionSortVector(num_vector, left, mid);
	mergeInsertionSortVector(num_vector, mid + 1, right);
	mergeVector(num_vector, left, mid, right);
}

void mergeList(std::list<int>& left, std::list<int>& right, std::list<int>& result)
{
	result.clear();
	while (!left.empty() && !right.empty()) {
		if (left.front() <= right.front()) {
			result.push_back(left.front());
			left.pop_front();
		} else {
			result.push_back(right.front());
			right.pop_front();
		}
	}
	result.insert(result.end(), left.begin(), left.end());
	result.insert(result.end(), right.begin(), right.end());
}

void mergeInsertionSortList(std::list<int>& num_list)
{
	if (num_list.size() <= 1)
		return;

	if (num_list.size() <= 10)
	{
		num_list.sort();
		return;
	}

	std::list<int> left;
	std::list<int> right;
	int middle = num_list.size() / 2;
	std::list<int>::iterator it = num_list.begin();
	std::advance(it, middle);

	left.splice(left.begin(), num_list, num_list.begin(), it);
	right.splice(right.begin(), num_list, it, num_list.end());

	mergeInsertionSortList(left);
	mergeInsertionSortList(right);

	mergeList(left, right, num_list);
}
