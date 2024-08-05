/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 03:17:40 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 03:52:18 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T>
Array<T>::Array() : n(0) 
{
	this->array = new T[n];
}

template <class T>
Array<T>::Array(unsigned int n) : n(n) 
{
	this->array = new T[this->n];
	for(unsigned int i = 0; i < this->n; i++)
		this->array[i] = T();
}

template <class T>
Array<T>::Array(const Array& copy) : n(copy.n) 
{
	this->array = new T[this->n];
	for(unsigned int i = 0; i < this->n; i++)
		this->array[i] = copy.array[i];
}

template <class T>
Array<T>::~Array() 
{
	delete[] this->array;
}

template <class T>
Array<T>& Array<T>::operator=(const Array& rhs) 
{
	if(this != &rhs)
	{
		delete[] this->array;
		this->n = rhs.n;
		this->array = new T[this->n];
		for(unsigned int i = 0; i < this->n; i++)
			this->array[i] = rhs.array[i];
	}
	return (*this);
}

template <class T>
unsigned int Array<T>::size() const
{
	return (this->n);
}

template <class T>
T& Array<T>::operator[](unsigned int index)
{
	if(index >= this->n)
		throw Array::OutOfLimits();
	return (this->array[index]);
}

template <class T>
const char* Array<T>::OutOfLimits::what() const throw()
{
	return ("Index was out of limits");
}