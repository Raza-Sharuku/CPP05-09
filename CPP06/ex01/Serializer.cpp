/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:02:24 by razasharuku       #+#    #+#             */
/*   Updated: 2024/03/19 10:39:14 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &serializer)
{
	*this = serializer;
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	if (this != &rhs)
        return (*this);
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t raw;
    
    raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *ptr;

    ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}