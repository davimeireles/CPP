/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:03:36 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/07 17:03:37 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <stddef.h>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <limits>
#include <limits.h>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook() : indexContacts(0), totalContacts(0) {}
	void		DisplayHeader();
	void		DisplayOptions();
	void		DisplayContacts();
	void		ChooseOption(string option);
	void		AddNewContact();
	void		LeavePhoneBook();
	void		Trim(string &str);
	string		InputReader(string arg);
	string		TruncateText(string text);
	string		CapitalizeLetters(string option);
	Contact		CreateNewContact();

private:
	int 				indexContacts;
	int 				totalContacts;
	static const int 	MAX_CONTACTS = 8;
	Contact				Contacts[MAX_CONTACTS];
};

#endif
