/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:03:16 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/07 17:03:18 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void	PhoneBook::DisplayHeader()
{
	system ("clear");
	cout << endl;
	cout << "\033[94m";
	cout << "██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗\n"
			"██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝\n"
			"██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝ \n"
			"██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗ \n"
			"██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗\n"
			"╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝\n";
	cout << "\033[0m" << endl;
	cout << endl;
}

void	PhoneBook::DisplayOptions()
{

	cout << "			|\033[32mADD\033[0m";
	cout << "|\033[33mSEARCH\033[0m";
	cout << "|\033[31mEXIT\033[0m|";
	cout << endl;
	cout << endl;
	cout << "Choose an option: ";
	cout << endl;
}

void	PhoneBook::ChooseOption(string option)
{
	option = CapitalizeLetters(option);
	if (option == "ADD")
		AddNewContact();
	else if (option == "SEARCH")
		DisplayContacts();
	else if (option == "EXIT")
		LeavePhoneBook();
	else
	{
		cout << "Invalid option." << endl;
		sleep(1);
	}
}

Contact PhoneBook::CreateNewContact()
{
	Contact New;

	New.setFirstName(InputReader("First Name: "));
	New.setLastName(InputReader("Last Name: "));
	New.setNickName(InputReader("Nick Name: "));
	New.setPhoneNumber(InputReader("Phone Number: "));
	New.setDarkestSecret(InputReader("Darkest Secret: "));
	return (New);
}

void	PhoneBook::AddNewContact()
{
	if (indexContacts == MAX_CONTACTS)
		indexContacts = 0;
	Contact newContact = CreateNewContact();
	Contacts[indexContacts] = newContact;
	if (totalContacts != MAX_CONTACTS)
		totalContacts++;
	indexContacts++;
}

string	PhoneBook::InputReader(string arg)
{
	string helper;

	DisplayHeader();
	cout << arg << endl;
	std::getline(cin, helper);
	while(helper.empty())
	{
		cout << "Field can't be empty." << endl;
		sleep(2);
		DisplayHeader();
		cout << arg << endl;
		std::getline(cin, helper);
	}
	Trim(helper);
	return (helper);
}

void	PhoneBook::DisplayContacts()
{
	int	index = 0;
	string	input;
	bool	validInput = false;

	if (totalContacts == 0)
	{
		cout << "No contacts to display." << endl;
		sleep(2);
		return ;
	}
	system("clear");
	cout << std::setw(10) << "Index" << "|";
	cout << std::setw(10) << "First Name" << "|";
	cout << std::setw(10) << "Last Name" << "|";
	cout << std::setw(10) << "Nickname" << endl;
	for (int i = 0; i < totalContacts; i++) 
	{
		cout << std::setw(10) << i << "|";
		cout << std::setw(10) << TruncateText(Contacts[i].getFirstName()) << "|";
		cout << std::setw(10) << TruncateText(Contacts[i].getLastName()) << "|";
		cout << std::setw(10) << TruncateText(Contacts[i].getNickName()) << endl;
	}
	cout << endl;
	cout << endl;
	while (!validInput) 
	{
		cout << std::setw(10) << "Choose an index to display contact: ";
		getline(std::cin, input);
		std::istringstream iss(input);
		if (iss >> index && iss.eof()) {
			validInput = true;
		} else {
			cout << "Invalid index. Please enter a valid integer." << endl;
		}
		if (validInput)
		{
			if (index < 0 || index >= totalContacts)
			{
				cout << "Invalid index. Please enter a valid integer." << endl;
				validInput = false;
			}
		}
	}
	std::cout << std::endl << std::endl;
	cout << std::setw(10) << "|Index" << "|";
	cout << std::setw(10) << "First Name" << "|";
	cout << std::setw(10) << "Last Name" << "|";
	cout << std::setw(10) << "Nickname" << "|";
	cout << std::setw(10) << "Phone Number" << "|";
	cout << std::setw(10) << "Darkest Secret|" << endl;
	cout << std::setw(10) << index << "|";
	cout << std::setw(10) << TruncateText(Contacts[index].getFirstName()) << "|";
	cout << std::setw(10) << TruncateText(Contacts[index].getLastName()) << "|";
	cout << std::setw(10) << TruncateText(Contacts[index].getNickName()) << "|";
	cout << std::setw(10) << TruncateText(Contacts[index].getPhoneNumber()) << "|";
	cout << std::setw(10) << TruncateText(Contacts[index].getDarkestSecret()) << "|" <<endl;
	std::cout << std::endl << std::endl;
	cout << std::setw(10) << "Press enter to continue...";
	std::cin.get();
}

string PhoneBook::TruncateText(string text) 
{
	if (text.length() > 10)
		return text.substr(0, 9) + ".";
	else
		return text;
}

void	PhoneBook::LeavePhoneBook()
{
	system("clear");
	cout << endl;
	cout << "\033[94m";
	cout << "███████╗███████╗███████╗    ██╗   ██╗ ██████╗ ██╗   ██╗\n"
			"██╔════╝██╔════╝██╔════╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║\n"
			"███████╗█████╗  █████╗       ╚████╔╝ ██║   ██║██║   ██║\n"
			"╚════██║██╔══╝  ██╔══╝        ╚██╔╝  ██║   ██║██║   ██║\n"
			"███████║███████╗███████╗       ██║   ╚██████╔╝╚██████╔╝\n"
			"╚══════╝╚══════╝╚══════╝       ╚═╝    ╚═════╝  ╚═════╝ \n";
	cout << "\033[0m" << endl;
	cout << endl;
	exit(EXIT_SUCCESS);
}

void	PhoneBook::Trim(string &str)
{
	string::iterator it = str.begin();
	while (it != str.end() && std::isspace(*it))
		++it;
	str.erase(str.begin(), it);

	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend() && std::isspace(*rit))
		++rit;
	str.erase(rit.base(), str.end());
}

string PhoneBook::CapitalizeLetters(string option)
{
	for (size_t i = 0; i < option.length(); i++)
	{
		if (std::isalpha(option[i]))
			option[i] = std::toupper(option[i]);
	}
	return (option);
}