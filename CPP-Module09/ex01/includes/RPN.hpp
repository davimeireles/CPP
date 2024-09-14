/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:50:21 by dmeirele          #+#    #+#             */
/*   Updated: 2024/09/15 00:17:56 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "inc.hpp"

void	parsing(string argument);
bool	checkWhiteSpaces(string str);
bool	checkInput(string str);
bool	checkFormat(string str);
bool	isNumber(string str);
bool	calculate(std::stack<int>& stack_numbers, string op);
string	integerToString(int value);
