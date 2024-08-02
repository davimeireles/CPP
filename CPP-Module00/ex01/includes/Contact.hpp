/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:03:31 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/07 17:03:32 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::cin;

class Contact
{
private:
	string FirstName;
	string LastName;
	string NickName;
	string PhoneNumber;
	string DarkestSecret;

public:
	string		getFirstName();
	string		getLastName();
	string		getNickName();
	string		getPhoneNumber();
	string		getDarkestSecret();
	void		setFirstName(string FirstName);
	void		setLastName(string LastName);
	void		setNickName(string NickName);
	void		setPhoneNumber(string PhoneNumber);
	void		setDarkestSecret(string DarkestSecret);
};

#endif
