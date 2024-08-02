/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:18:58 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/26 22:56:12 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


static void fillVec(std::vector<int>& newVec)
{
	srand((unsigned)time(NULL));
	for (unsigned int i = 0; i < 10000; i++)
	{
		unsigned int n = rand() % 10000;
		newVec.push_back(n);
	}
}

void	menu()
{
	int	op;

	std::cout << DarkGray << "--- Select a option ---" << Reset << std::endl << std::endl;

	std::cout << Orange << "Menu:" << Reset << std::endl;
	std::cout << BrightBlack << "1 - Add Numbers With Simple Form" << std::endl;
	std::cout << "2 - Add Numbers With Otimized Form" << std::endl;
	std::cout << "3 - Exit Program" << Reset << std::endl;
	std::cin >> op;
	if (std::cin.fail())
		op = 0;
	switch(op)
	{
		case 1:
		{
			Span newSpan(10);
			newSpan.addNumber(1);
			newSpan.addNumber(10);
			newSpan.addNumber(100);
			newSpan.addNumber(20);
			newSpan.addNumber(30);
			break ;
		}
		case 2:
		{
			std::vector<int>::iterator begin;
			std::vector<int>::iterator end;
			std::vector<int> newVec(10000);
			fillVec(newVec);
			begin = newVec.begin();
			end = newVec.end();
			Span newSpan(newVec.size());
			newSpan.addVector(begin, end);
			break ;
		}
		case 3:
			exit(0);
		case 0:
		{
			std::cout << "Invalid Option" << std::endl;
			break;
		}
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	menu();
}

int main()
{
	system("clear");
	menu();
}