/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:02 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/15 11:55:31 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

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