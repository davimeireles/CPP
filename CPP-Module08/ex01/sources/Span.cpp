/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:18:14 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/26 22:55:50 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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

void Span::addNumber(unsigned int newNumber)
{
	try
	{
		if (this->filledNumbers < this->maxNumbers)
		{
			this->data.push_back(newNumber);
			filledNumbers++;
			std::cout << Cyan << "Number Added Inside Contentor" << Reset << std::endl;
		}
		else
			throw std::runtime_error("Max Number Of Elements Reached");
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset <<'\n';
	}
	
}

void Span::addVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	try
	{
		if (this->filledNumbers < this->maxNumbers)
		{
		for (;begin != end; begin++)
		{
			this->data.push_back(*begin);
			filledNumbers++;
			std::cout << Cyan << "Number Added Inside Contentor" << Reset << std::endl;
		}
		}
		else
			throw std::runtime_error("Max Number Of Elements Reached");
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset << '\n';
	}
}
