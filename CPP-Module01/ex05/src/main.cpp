/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:02:04 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/09 13:41:58 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main( void )
{
	Harl robot;

	std::string strList[4] =
	{
		"debUg",
		"iNFO",
		"warNiNg",
		"errOr"
	};

	for(unsigned long i = 0; i < 4; i++)
		robot.complain(strList[i]);
}
