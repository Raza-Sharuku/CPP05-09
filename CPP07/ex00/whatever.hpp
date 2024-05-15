/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:02 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/15 11:36:51 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string.h>
#include <exception>
#include <iomanip>

template <typename T>
void swap(T &x, T &y)
{
    T z = x;
    x = y;
    y = z;
};

template <typename E>
E const min(E const x, E const y)
{
    if (x >= y)
        return (y);
    else 
        return (x);
};

template <typename M>
M const max(M const x, M const y)
{
    if (x <= y)
        return (y);
    else 
        return (x);
};


#endif