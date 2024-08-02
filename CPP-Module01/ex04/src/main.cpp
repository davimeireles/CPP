/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:11:28 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/09 15:01:07 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

int	OpenFile(char *fileName, std::string original, std::string replace)
{
	std::string		line;
	std::ifstream 	file(fileName);
	strcat(fileName, ".replace");

	if (file.is_open())
	{
		std::ofstream	newFile(fileName);
		while (getline(file,line))
		{
			size_t	pos = 0;
			while ((pos = line.find(original, pos)) != std::string::npos)
			{
				line.erase(pos, original.size());
				line.insert(pos, replace);
				pos += replace.size();
			}
			newFile << line;
			if (!file.eof())
				newFile << std::endl;
		}
		file.close();
		newFile.close();
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		if(!OpenFile(argv[1], argv[2], argv[3]))
			std::cerr << "File cannot be open" << std::endl;
	}
	else
	{
		std::cout << "Invalid number of parameters." << std::endl;
		std::cout << "You need to insert in the following order: " << std::endl;
		std::cout << "[File Name], [String 1], [String 2]." << std::endl;
	}
	return (0);
}
