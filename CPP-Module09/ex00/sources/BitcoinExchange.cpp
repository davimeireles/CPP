/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:33:42 by dmeirele          #+#    #+#             */
/*   Updated: 2024/09/14 09:58:32 by dmeirele         ###   ########.fr       */
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
	if (!checkFile(filename))
		return ;
	if (!checkFile("data.csv"))
		return ;
	extractDataToMap("data.csv");
	compareInputWithData(filename);
}

bool BitcoinExchange::checkFile(const string &filename)
{
	std::ifstream file(filename.c_str());
	bool	err = true;

	if (!file.is_open())
	{
		printError("Error: cannot open the file.");
		err = false;
	}
	else if (checkIsEmpty(file))
	{
		printError("Error: empty input file");
		err = false;
	}
	else if (filename == "data.csv" && !checkDataFirstLine(file))
	{
		printError("Error: data first line must be \"date,exchange_rate\"");
		err = false;
	}
	file.close();
	return (err);
}

bool BitcoinExchange::checkIsEmpty(std::ifstream &file)
{
	return (file.peek() == std::ifstream::traits_type::eof());
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
			string date = line.substr(0, commaPos);
			string value = line.substr(commaPos + 1, line.size());
			char* endptr;
			float result = strtof(value.c_str(), &endptr);
			_data[date] = result;
		}
	}
	dataFile.close();
}

void BitcoinExchange::compareInputWithData(const string &filename)
{
	std::ifstream inputFile(filename.c_str());

	string	dummy;
	string	line;

	getline(inputFile, dummy);
	if (dummy != "date | value")
	{
		cout << RED << "Error: first line must be [date | value]" << RESET << endl;
		return ;
	}
	while(getline(inputFile, line))
	{
		size_t	divPos = line.find('|');
		string	date = line.substr(0, divPos);
		string	amount = line.substr(divPos + 1, line.size());
		trim(date);
		trim(amount);
		char* endptr;
		float	_amount = strtof(amount.c_str(), &endptr);
		if (!checkPositiveAmount(_amount))
			cout << RED << "Error: not a positive number." << RESET << endl;
		else if (!isNumber(amount) || !checkFormat(amount))
			cout << RED << "Error: bad input => " << date << RESET << endl;
		else if (checkOverflowAmount(_amount))
			cout << RED << "Error: too large a number." << RESET << endl;
		else if (!checkValidDate(date, _amount))
			cout << RED << "Error: bad input => " << date << RESET << endl;
	}
	inputFile.close();
}

bool BitcoinExchange::checkValidDate(string date, float _amount)
{
	size_t	divPos = date.find('-');
	size_t	secondDivPos;
	string	year;
	string	month;
	string	day;

	if (divPos != string::npos)
	{
		year = date.substr(0, divPos);
		for (unsigned int i = 0; i < year.size(); i++)
		{
			if (!isdigit(year[i]))
				return (false);
		}
		secondDivPos = date.find('-', divPos + 1);
		month = date.substr(divPos + 1, (secondDivPos - 1) - divPos);
		for (unsigned int i = 0; i < month.size(); i++)
		{
			if (!isdigit(month[i]))
				return (false);
		}
		if (secondDivPos != string::npos)
		{
			day = date.substr(secondDivPos + 1, date.size() - secondDivPos);
			for (unsigned int i = 0; i < day.size(); i++)
			{
				if (!isdigit(day[i]))
					return (false);
			}
		}
	}

	int	_year = atoi(year.c_str());
	int	_month = atoi(month.c_str());
	int	_day = atoi(day.c_str());

	if ((_year > 2024 || _year < 2009)
		|| (_month < 1 || _month > 12)
			|| (_day < 1 || _day > 31))
		return (false);

	std::map<std::string, float>::iterator current;
	std::map<std::string, float>::iterator previous;

	if (checkLeapYear(_year) && _month == 2 && _day > 29)
		_day = 29;
	else if (!checkLeapYear(_year) && _month == 2 && _day > 28)
		_day = 28;

	std::string adjustedDate = date.substr(0, 8) + (_day < 10 ? "0" : "") + integerToString(_day);

	if (adjustedDate > _data.rbegin()->first)
	{
		makeExchange(_data.rbegin()->first, _amount, adjustedDate);
		return true;
	}

	previous = _data.begin();
	current = _data.begin();
	current++;
	while (current != _data.end())
	{
		if (current->first > adjustedDate)
		{
			makeExchange(previous->first, _amount, date);
			return (true);
		}
		previous = current;
		++current;
	}
	return (false);
}

bool	BitcoinExchange::checkLeapYear(int	year)
{
	if (year % 4 != 0)
		return false;
	if (year % 100 != 0)
		return true;
	if (year % 400 != 0)
		return false;
	return true;
}

string BitcoinExchange::integerToString(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

bool BitcoinExchange::makeExchange(string date, float _amount, string dateToPrint)
{
	std::map<string, float>::iterator it = _data.find(date);

	if (it != _data.end())
	{
		cout << GREEN << dateToPrint << " => " << _amount << " = " << (_amount * it->second) << RESET << endl;
		return (true);
	}
	return (false);
}

bool BitcoinExchange::checkPositiveAmount(float _amount)
{
	if (_amount < 0)
		return (false);
	return (true);
}

bool BitcoinExchange::checkOverflowAmount(float _amount)
{
	if (_amount > 1000)
		return (true);
	if (_amount <= INT_MIN)
		return (true);
	return (false);
}

void BitcoinExchange::printError(string error)
{
	std::cerr << RED << error << endl << RESET;
}

void BitcoinExchange::trim(string &str)
{
	int end = str.size() - 1;
	while(end > 0 && isspace(str[end]))
		end--;
	str.erase(end + 1);
	unsigned int i = 0;
	while(i < str.size() && isspace(str[i]))
		i++;
	str.erase(0, i);
}

bool	BitcoinExchange::isNumber(string str)
{
	if (std::isdigit(str[0]))
		return (true);
	if ((str[0] == '-' || str[0] == '+'))
	{
		if (str[1] && std::isdigit(str[1]))
			return (true);
	}
	return (false);
}

bool	BitcoinExchange::checkFormat(string str)
{
	int	i = 0;
	int countDots = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
		else if (str[i] == '.')
			countDots++;
		i++;
	}
	if (countDots > 1)
		return (false);
	return (true);
}