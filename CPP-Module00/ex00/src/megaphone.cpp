/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:03:40 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/07 17:03:41 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string capitalize_letters(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return (str);
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for(int i = 1; i < argc; i++)
			std::cout << capitalize_letters(argv[i]);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
