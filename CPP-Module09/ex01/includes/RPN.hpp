/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:50:21 by dmeirele          #+#    #+#             */
/*   Updated: 2024/09/03 19:04:57 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "inc.hpp"

void					parsing(string argument);
void					trim(string &str);
bool					isOperator(char* str);
bool					checkFormat(char* str);
bool					isNumber(string str);
bool					isValidInput(char* str);
void					calculate(std::vector<string> argumentVector);
void					free_pointers(char* argCopy, char** array_ag, int i);


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


