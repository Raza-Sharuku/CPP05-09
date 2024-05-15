/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:24:39 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/15 17:52:51 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


template <typename T>
Array<T>::Array(void) : elements(NULL), length(0)
{    
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), length(n)
{    
}

template <typename T>
Array<T>::Array(const Array &other) : elements(new T[other.length]), length(other.length)
{
    unsigned int i = 0;
    while (i < length)
    {
        this->elements[i] = other.elements[i];
        i++;
    }
    return ;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete [] elements;
        this->length = other.length;
        elements = new T[length];
        unsigned int i = 0;
        while (i < length)
        {
            this->elements[i] = other.elements[i];
            i++;
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
    delete [] this->elements;
}



int main() 
{
	std::cout << "\033[1;33m" << "++++++++++++++++++ test start 1 ++++++++++++++++\n" << "\033[0m" << std::endl;


	std::cout << "\033[1;33m" << "\n++++++++++++++++++ test finish 1 +++++++++++++++" << "\033[0m" << std::endl;
	std::cout << "\033[1;36m" << "++++++++++++++++++ test start 2 ++++++++++++++++\n" << "\033[0m" << std::endl;


	std::cout << "\033[1;36m" << "\n++++++++++++++++++ test finish 2 +++++++++++++++\n" << "\033[0m" << std::endl;

    return 0;
}