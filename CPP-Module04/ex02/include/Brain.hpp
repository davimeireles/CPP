/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:27:07 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/26 11:31:53 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain{

	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &original);
		~Brain();
		Brain& operator=(Brain const &rhs);
};

#endif