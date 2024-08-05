/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 04:12:36 by dmeirele          #+#    #+#             */
/*   Updated: 2024/08/05 04:36:02 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "inc.hpp"

template <typename T>
int	easyfind(T& container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw (std::exception());
	return (std::distance(container.begin(), it));
}