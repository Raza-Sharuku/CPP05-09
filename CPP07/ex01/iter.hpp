/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:02 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/16 11:00:39 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename Function>
void iter(T *array, size_t len_of_array, Function func)
{
    size_t i = 0;
    while (i < len_of_array)
    {
        func(array[i]);
        ++i;
    }
    return ;
};


template <typename E>
void print(E& element) 
{
    std::cout << element << " ";
}

template <typename M>
void multiply_Two(M& element) 
{
    element *= 2;
}


#endif