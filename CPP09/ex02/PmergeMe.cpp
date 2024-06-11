/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:59:30 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/11 14:51:33 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const std::string &str)
{
    

    return ;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
    return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
    }
    return (*this);
}

PmergeMe::~PmergeMe(void)
{
}


