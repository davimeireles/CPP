/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:22:00 by dmeirele          #+#    #+#             */
/*   Updated: 2024/09/06 12:09:47 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

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
	int	num;

	for (int i = 1; argv[i]; i++)
	{
		num = std::atoi(argv[i]);
		if (num < 0)
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
