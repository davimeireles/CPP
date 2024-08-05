/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:18:58 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 06:26:17 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inc.hpp"
#include "../includes/Span.hpp"

static void enter_to_continue()
{
	cout << "\n\nPress |ENTER| to continue" << endl;
	std::cin.get();
	system("clear");
}

static void SubjectTest()
{
	try
	{
		Span sp = Span(5);

		cout << Orange << "Adding numbers to the vector..." << endl << Reset;
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		cout << endl;
		cout << Orange << "Testing Member Functions..." << endl << Reset;
		cout << Purple << "Vector Values:" << Reset;
		sp.printDataNumbers();
		
		cout << endl;
		cout << Purple <<"Sorted Vector Values:" << Reset;
		sp.printSortedDataNumbers();

		cout << endl;
		cout << Cyan <<"Shortest Span: "  << Reset << sp.shortestSpan() << endl;
		cout << Cyan << "Longest Span: " << Reset << sp.longestSpan() << endl;
	}
	catch (std::exception &e)
	{
		cout << Red << e.what() << Reset << endl;
	}
	enter_to_continue();
}

static void SpanUsingIterators()
{

	try
	{
		std::vector<int> v;
		std::vector<int>::iterator begin;
		std::vector<int>::iterator end;

		cout << Orange << "Adding numbers to V vector..." << endl << Reset;
		for(unsigned int i = 0; i < 10; i++)
		{
			v.push_back(rand() % 100);
			cout << Purple << "Vector Value: " << Reset << v[i] << endl;
		}

		Span span(10);

		begin = v.begin();
		end = v.end();

		cout << endl;
		cout << Orange << "Adding numbers to data vector using range of iterators..." << endl << Reset;
		span.addVector(begin, end);

		cout << endl;
		cout << Orange << "Testing Member Functions..." << endl << Reset;
		cout << Purple << "Span Data Values:" << Reset;
		span.printDataNumbers();

		cout << endl;
		cout << Purple <<"Sorted Vector Values:" << Reset;
		span.printSortedDataNumbers();

		cout << endl;
		cout << Cyan <<"Shortest Span: "  << Reset << span.shortestSpan() << endl;
		cout << Cyan << "Longest Span: " << Reset << span.longestSpan() << endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset << '\n';
	}
	enter_to_continue();
}

static void TestExceptions()
{
	try
	{
		Span sp = Span(5);

		cout << Orange << "Add Numbers Exception" << endl << Reset;
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		cout << Red << e.what() << Reset << endl;
	}

	try
	{
		Span sp(1);

		cout << endl;
		cout << Orange << "Shortest/Longest Span Exception" << endl << Reset;
		sp.addNumber(5);

		cout << endl;
		cout << Cyan << "Shortest Span: "  << Reset << sp.shortestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset << '\n';
	}
	enter_to_continue();
}

int main()
{
	SubjectTest();
	SpanUsingIterators();
	TestExceptions();
	return (0);
}