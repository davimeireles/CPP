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

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

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


		void	checkFile(const string &filename);
		bool	checkOpenFile(std::ifstream &file);
		bool	checkIsEmpty(std::ifstream &file);
		bool	checkInputFirstLine(std::ifstream &file);

		bool	checkDataFirstLine(std::ifstream &file);


		void	printError(string error, std::ifstream &file);
};

#endif