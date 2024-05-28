/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:00:46 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/27 11:21:46 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <iterator>


template <typename T>
typename T::value_type const& easyfind(T const& array, int num)
{
    typename T::const_iterator find_value = std::find(array.begin(), array.end(), num);
    if (find_value == array.end())
        throw std::out_of_range("Couldn't found in Array");
    return (*find_value);
}


#endif