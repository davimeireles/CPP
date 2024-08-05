/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 06:30:49 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 08:04:11 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include "../includes/inc.hpp"

static void enter_to_continue()
{
	cout << "\n\nPress |ENTER| to continue" << endl;
	std::cin.get();
	system("clear");
}

static void PrintListElements(std::list<int> &lst)
{
	std::list<int>::reverse_iterator it = lst.rbegin();
	std::list<int>::reverse_iterator ite = lst.rend();
	
	cout << Orange << "Iterating through List" << Reset << endl;

 	for(; it != ite; ++it)
	{
		cout << Orange << "Element: " << Reset << *it << endl;
	}
}

static void PrintStackElements(MutantStack<int> &mstack)
{
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	
	cout << Orange << "Iterating through Stack" << Reset << endl;

 	for(; it != ite; ++it)
	{
		cout << Orange << "Element: " << Reset << *it << endl;
	}
}

static void SubjectTest()
{
	try
	{
		MutantStack<int> mstack;
		cout << Cyan << "Pushing 5, 17 to Stack" << Reset << endl;
		mstack.push(5);
		mstack.push(17);
		cout << Orange << "Top of Stack: " << Reset << endl;
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		cout << Orange << "Stack size: " << Reset << endl;
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		cout << Orange << "Iterating through Stack" << Reset << endl;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset << '\n';
	}
	enter_to_continue();
}

static void SubjectTestRemixed()
{
	try
	{
		MutantStack<int> mstack;
		
		cout << Cyan << "Pushing 5, 17 to Stack" << Reset << endl;
		mstack.push(5);
		mstack.push(17);

		cout << endl;
		PrintStackElements(mstack);
		cout << endl;
		
		cout << Orange << "Top of Stack: " << Reset << mstack.top() << endl << endl;
		
		cout << Cyan << "Poping from Stack" << Reset << endl;
		mstack.pop();
		cout << endl;
		PrintStackElements(mstack);
		cout << endl;
		
		cout << Orange << "Stack size: " << Reset << mstack.size() << endl << endl;
		
		cout << Cyan << "Pushing 3, 5, 737, 0 to Stack" << Reset << endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		cout << endl;
		PrintStackElements(mstack);
		cout << endl;
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset << '\n';
	}
	enter_to_continue();
}

static void TestWithList()
{
	try
	{
		cout << Purple << "--- Test With List ---" << endl << Reset;
		std::list<int> lst;
		
		cout << Cyan << "Pushing 5, 17 to List" << Reset << endl;
		lst.push_back(5);
		lst.push_back(17);
	
		cout << endl;
		PrintListElements(lst);
		cout << endl;
		
		cout << Orange << "Top of List: " << Reset << lst.back() << endl << endl;
		
		cout << Cyan << "Poping from List" << Reset << endl;
		lst.pop_back();
		
		cout << endl;
		PrintListElements(lst);
		cout << endl;
		
		cout << Orange << "List size: " << Reset << lst.size() << endl << endl;


		cout << Cyan << "Pushing 3, 5, 737, 0 to List" << Reset << endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		cout << endl;
		PrintListElements(lst);
		cout << endl;
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
	SubjectTestRemixed();
	TestWithList();
	return (0);
}
