/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:32:57 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/23 01:20:23 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

#define Black "\033[30m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Magenta "\033[35m"
#define Cyan "\033[36m"
#define Reset "\033[0m"
#define Orange "\033[38;5;208m"

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;

	public:
		Array() : _array(0), _size(0) {}

		Array(unsigned int n) : _array(new T[n]), _size(n) {
			for (unsigned int i = 0; i < n; i++)
				_array[i] = T();
		}

		Array(Array const &original) : _array(new T[original._size]), _size(original._size)
		{
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = original._array[i];
		}
		
		Array& operator=(Array const &rhs)
		{
			if (this == &rhs)
				return *this;
			delete[] _array;
			_size = rhs._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
			return *this;
		}
		
		unsigned int size() const
		{
			return _size;
		}

		~Array(){delete[] _array;}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _array[index];
		}
		
		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _array[index];
		}
};


#endif