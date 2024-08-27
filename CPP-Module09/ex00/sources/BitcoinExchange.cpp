/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:33:42 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 09:19:03 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include "../includes/inc.hpp"

BitcoinExchange::BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_data = other._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void){}

void BitcoinExchange::exchange(const string &filename)
{
	checkFile(filename);
	checkFile("data.csv");
	extractDataToMap("data.csv");
}

void BitcoinExchange::checkFile(const string &filename)
{
	std::ifstream file(filename.c_str());

	if (!checkOpenFile(file))
		printError("Error: could not open file", file);
	if (checkIsEmpty(file))
		printError("Error: empty input file", file);
	if (filename == "input.txt" && !checkInputFirstLine(file))
		printError("Error: input first line must be \"date | value\"", file);
	if (filename == "data.csv" && !checkDataFirstLine(file))
		printError("Error: data first line must be \"date,exchange_rate\"", file);
	file.close();
}

bool BitcoinExchange::checkOpenFile(std::ifstream &file)
{
	if (!file.is_open())
		return (false);
	return (true);
}

bool BitcoinExchange::checkIsEmpty(std::ifstream &file)
{
	return (file.peek() == std::ifstream::traits_type::eof());
}

bool BitcoinExchange::checkInputFirstLine(std::ifstream &file)
{
	string line;

	getline(file, line);
	if (line != "date | value")
		return (false);
	return (true);
}

bool BitcoinExchange::checkDataFirstLine(std::ifstream &file)
{
	string line;

	getline(file, line);
	if (line != "date,exchange_rate")
		return (false);
	return (true);
}

void BitcoinExchange::extractDataToMap(const string &filename)
{
	std::ifstream dataFile(filename.c_str());

	string	line;
	string	dummy;

	getline(dataFile, dummy);
	while (dataFile)
	{
		getline(dataFile, line);
		size_t commaPos = line.find(',');
		if (commaPos != string::npos)
		{
			string firstpart = line.substr(0, commaPos);
			string secondpart = line.substr(commaPos + 1, line.size());
			char* endptr;
			float result = strtof(secondpart.c_str(), &endptr);
			_data[firstpart] = result;
		}
	}
	dataFile.close();
	std::map<string, float>::iterator it = _data.begin();
	for(;it != _data.end(); ++it)
	{
		cout << it->first << " | " << it->second << endl;
	}
}

void BitcoinExchange::printError(string error, std::ifstream &file)
{
	std::cerr << RED << error << endl << RESET;
	file.close();
	exit(EXIT_FAILURE);
}