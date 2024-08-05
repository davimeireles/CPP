/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 06:30:51 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 07:37:47 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "inc.hpp"

template <class T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <class T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other) {}

template <class T>
MutantStack<T>::~MutantStack(void) {}

template <class T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const &other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return (*this);
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) {
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) {
	return (this->c.end());
}

template <class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void) {
	return (this->c.rbegin());
}

template <class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void) {
	return (this->c.rend());
}