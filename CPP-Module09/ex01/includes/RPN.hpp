/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:50:21 by dmeirele          #+#    #+#             */
/*   Updated: 2024/09/04 21:45:20 by dmeirele         ###   ########.fr       */
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


/* Tests that need to fail (error msg) */
/*
 * ./RPN ""
 * ./RPN "      "
 * ./RPN " 1 2"
 * ./RPN "     1     2    "
 * ./RPN " - 1 2 "
 * ./RPN " - - 1 2 "
 * ./RPN "1 1 -2 - 2 * 3a +"
 * ./RPN "1 - 1 -2 - 2 * 3 +"
 * ./RPN "1 1 ---------2 - 2 * 3 +"
 * ./RPN "1 1 2------- - 2 * 3 +"
 * ./RPN "1 1 2 ------ 2 * 3 +"
 * ./RPN "1 1 2 +/-* 2 * 3 + "
 * ./RPN "1 -1          +         2 * 3 +"
 *
 * */


