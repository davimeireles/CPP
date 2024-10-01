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

void	mergeInsertionSortVector(std::vector<int>& num_vector, int left, int right);
void	insertionSortVector(std::vector<int>& num_vector, int left, int right);
void	mergeVector(std::vector<int>& num_vector, int left, int mid, int right);

void mergeInsertionSortList(std::list<int>& num_list);
void mergeList(std::list<int>& left, std::list<int>& right, std::list<int>& result);

void	fordJohnsonSort(std::vector<int>& vec);