/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:21:43 by dmeirele          #+#    #+#             */
/*   Updated: 2024/10/01 17:19:04 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "inc.hpp"

void	PmergeMe(char** argv);
bool	parsing(char** argv);
bool	checkFormat(string str);
bool	isNumber(string str);

void	fordJohnsonSortVector(std::vector<int>& vec);
void	binaryInsertVector(std::vector<int>& vec, int start, int end, int value);

void	fordJohnsonSortList(std::list<int>& lst);
void	binaryInsertList(std::list<int>& lst, int value);
