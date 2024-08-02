/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:03:22 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/07 20:27:15 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int main(void)
{
	string option;
	PhoneBook PhoneBook;

	while (1)
	{
		PhoneBook.DisplayHeader();
		PhoneBook.DisplayOptions();
		std::getline(cin, option);
		PhoneBook.ChooseOption(option);
	}
}
