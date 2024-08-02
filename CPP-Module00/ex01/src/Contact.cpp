/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:03:27 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/07 17:03:28 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

/* Get Class variables */

string Contact::getFirstName()
{
	if (!FirstName.empty())
		return (FirstName);
	throw std::runtime_error("Empty");
}

string Contact::getLastName()
{
	if (!LastName.empty())
		return (LastName);
	throw std::runtime_error("Empty");
}

string Contact::getNickName()
{
	if (!NickName.empty())
		return (NickName);
	throw std::runtime_error("Empty");
}

string Contact::getPhoneNumber()
{
	if (!PhoneNumber.empty())
		return (PhoneNumber);
	throw std::runtime_error("Empty");
}

string Contact::getDarkestSecret()
{
	if (!DarkestSecret.empty())
		return (DarkestSecret);
	throw std::runtime_error("Empty");
}

/* Set Class variables */

void Contact::setFirstName(string NewFirstName)
{
	if (FirstName.empty())
		FirstName = NewFirstName;
	else
		throw std::runtime_error("Contact already have a First Name");
}

void Contact::setLastName(string NewLastName)
{
	if (LastName.empty())
		LastName = NewLastName;
	else
		throw std::runtime_error("Contact already have a Last Name");
}

void Contact::setNickName(string NewNickName)
{
	if (NickName.empty())
		NickName = NewNickName;
	else
		throw std::runtime_error("Contact already have a Nick Name");
}

void Contact::setPhoneNumber(string NewPhoneNumber)
{
	if (PhoneNumber.empty())
		PhoneNumber = NewPhoneNumber;
	else
		throw std::runtime_error("Contact already have a Phone Number");
}

void Contact::setDarkestSecret(string NewDarkestSecret)
{
	if (DarkestSecret.empty())
		DarkestSecret = NewDarkestSecret;
	else
		throw std::runtime_error("Contact already have a Darkest Secret");
}
