/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:50:21 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/29 10:50:21 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "inc.hpp"

void					parsing(string argument);
void					p_error(string error);
void					trim(string &str);
bool					isOperator(string str);
bool					checkFormat(string str);
bool					isNumber(string str);
bool					isValidInput(string str);
void					calculate(std::vector<string> argumentVector);
std::vector<string> 	splitString(string& argument, char delimiter);



/* Tests that need to fail (error msg) */
/*
 * ./RPN ""
 * ./RPN "      "
 * ./RPN "1"
 * ./RPN " 1 2 "
 * ./RPN "1 2  "
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


