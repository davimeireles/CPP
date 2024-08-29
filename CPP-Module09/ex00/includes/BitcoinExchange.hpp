/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:48:34 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 08:50:59 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "inc.hpp"

class BitcoinExchange
{
	private:
		std::map<string, float> _data;
	
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void	exchange(const string &filename);
		void	extractDataToMap(const string &filename);
		void	compareInputWithData(const string &filename);
		bool	makeExchange(string date, float _amount, string dateToPrint);

		bool	checkFile(const string &filename);
		bool	checkIsEmpty(std::ifstream &file);
		bool	checkInputFirstLine(std::ifstream &file);

		bool	checkDataFirstLine(std::ifstream &file);
		bool	checkValidDate(string date, float _amount);
		bool	checkPositiveAmount(float _amount);
		bool	checkOverflowAmount(float _amount);

		void	printError(string error);
		void	trim(string &in);

		string	integerToString(int value);
};
