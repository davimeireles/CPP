/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:18:01 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 05:56:13 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include "inc.hpp"

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &original);
		~Span();

		Span &operator=(const Span &rhs);
		void addNumber(unsigned int N);
		void addVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		void printDataNumbers();
		void printSortedDataNumbers();
		unsigned int shortestSpan();
		unsigned int longestSpan();

	private:
		unsigned int maxNumbers;
		unsigned int filledNumbers;
		std::vector<unsigned int> data;
};



#endif