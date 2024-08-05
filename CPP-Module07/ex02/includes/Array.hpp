/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 03:17:42 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 03:51:01 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "inc.hpp"

template <class T>
class Array 
{
	private:
		T* array;
		unsigned int n;
	
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();

		Array& operator=(const Array& rhs);
		T& operator[](unsigned int index);

		unsigned int size() const;

		class OutOfLimits : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"
#endif