/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:00:46 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/01 13:26:41 by razasharuku      ###   ########.fr       */
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
typename T::iterator  easyfind(T& array, int num)
{
    typename T::iterator it = std::find(array.begin(), array.end(), num);
    if (it == array.end())
        throw std::out_of_range("Couldn't found in Array");
    return (it);
};

#endif