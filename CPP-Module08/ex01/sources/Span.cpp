/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:18:14 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 05:55:58 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(unsigned int N)
{
	this->filledNumbers = 0;
	this->maxNumbers = N;
	this->data.reserve(N);
}

Span::Span(Span const &original)
{
	data = original.data;
	filledNumbers = original.filledNumbers;
	maxNumbers = original.maxNumbers;
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		data = rhs.data;
		filledNumbers = rhs.filledNumbers;
		maxNumbers = rhs.maxNumbers;
	}
	return (*this);
}

Span::~Span(){}

void Span::printDataNumbers()
{
	std::vector<unsigned int>::iterator it;
	
	for (it = this->data.begin(); it != data.end(); it++)
	{
		cout << Yellow << " " << *it << Reset;
	}
}

void Span::printSortedDataNumbers()
{
	std::vector<unsigned int> sortedData = this->data;
	std::sort(sortedData.begin(), sortedData.end());
	std::vector<unsigned int>::iterator it;
	
	for (it = sortedData.begin(); it != sortedData.end(); it++)
	{
		cout << Yellow << " " << *it << Reset;
	}
}

unsigned int Span::shortestSpan()
{
	if (this->filledNumbers <= 1)
		throw std::runtime_error("Not Enough Elements To Calculate Span");
	else
	{
		std::vector<unsigned int> sortedData = this->data;
		std::sort(sortedData.begin(), sortedData.end());
		std::vector<unsigned int>::iterator it;
		unsigned int shortestSpan = UINT_MAX;
		unsigned int currentSpan;

		for (it = sortedData.begin(); it != sortedData.end() - 1; it++)
		{
			currentSpan = *(it + 1) - *it;
			if (currentSpan < shortestSpan)
				shortestSpan = currentSpan;
		}
		return (shortestSpan);
	}
}

unsigned int Span::longestSpan()
{
	if (this->filledNumbers <= 1)
		throw std::runtime_error("Not Enough Elements To Calculate Span");
	else
	{
		std::vector<unsigned int> sortedData = this->data;
		std::sort(sortedData.begin(), sortedData.end());
		return (sortedData.back() - sortedData.front());
	}
}

void Span::addNumber(unsigned int newNumber)
{
	if (this->filledNumbers >= this->maxNumbers)
		throw std::runtime_error("Max Number Of Elements Reached");
	else
	{
		this->data.push_back(newNumber);
		filledNumbers++;
		cout << Cyan << "Number Added Inside Contentor" << Reset << endl;
	}
}

void Span::addVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (;begin != end; begin++)
	{
		if (this->filledNumbers >= this->maxNumbers)
			throw std::runtime_error("Max Number Of Elements Reached");
		this->data.push_back(*begin);
		filledNumbers++;
		cout << Cyan << "Number Added Inside Contentor" << Reset << endl;
	}
}
