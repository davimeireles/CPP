/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:18:01 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/26 23:05:26 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

/* Headers Includes */
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <limits>

/* Colors */
#define BrightBlack "\033[90m"
#define BrightRed "\033[91m"
#define BrightGreen "\033[92m"
#define BrightYellow "\033[93m"
#define BrightBlue "\033[94m"
#define BrightMagenta "\033[95m"
#define BrightCyan "\033[96m"
#define BrightWhite "\033[97m"
#define White "\033[37m"
#define LightGray "\033[37m"
#define DarkGray "\033[90m"
#define LightRed "\033[91m"
#define LightGreen "\033[92m"
#define LightYellow "\033[93m"
#define LightBlue "\033[94m"
#define LightMagenta "\033[95m"
#define LightCyan "\033[96m"
#define LightWhite "\033[97m"
#define Orange "\033[38;5;208m"
#define Pink "\033[38;5;213m"
#define Purple "\033[38;5;129m"
#define Brown "\033[38;5;94m"
#define Reset "\033[0m"

class Span
{
	public:
	Span(unsigned int N);
	Span(const Span &original);
	~Span();

	Span &operator=(const Span &rhs);
	void addNumber(unsigned int N);
	void addVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	private:
	unsigned int maxNumbers;
	unsigned int filledNumbers;
	std::vector<unsigned int> data;

};



#endif