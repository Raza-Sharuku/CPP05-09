/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:24:38 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/28 10:55:22 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

Span::Span(unsigned int N) : m_maxnum(N)
{
    if (N  > INT_MAX)
        throw "N  > 2147483647. Can't set bigger value than INT_MAX";
    else if (N == 0)
        throw "N = 0. Can't set 0";
}

Span::Span(Span const &other) : m_maxnum(other.m_maxnum), array(other.array)
{
    *this = other;
    return ;
}

Span &Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->m_maxnum = other.m_maxnum;
        this->array = other.array;   
    }
    return (*this);
}

Span::~Span(void)
{
}

const int &Span::operator[](unsigned int i) const 
{
    if (i >= this->array.size())
    {
        throw std::out_of_range("Can't Access this element number. Out of Range");
    }
    return array[i];
}


int &Span::operator[](unsigned int i)
{
    if (i >= this->array.size())
    {
        throw std::out_of_range("Can't Access this element number. Out of Range");
    }
    return array[i];
}

// getter setter
const std::vector<int> Span::get_array(void) const 
{
    return (array);
}

void Span::set_array_value(int index, int num)
{
    this->array[index] = num;
    return ;
}


// メンバ関数
void Span::addNumber(int num)
{
    if (this->array.size() >= this->m_maxnum)
        throw std::out_of_range("Can't Add Numbers Anymore. Out of Range");
    array.push_back(num);
    return ;
}

void Span::add_number_at_once(const std::vector<int>& Array, size_t position)
{
    if (position >= this->array.size())
        throw std::out_of_range("Position is bigger than size of Current Span. Out of Range");
    if ((Array.size() + this->array.size()) >= this->m_maxnum)
        throw std::out_of_range("Array Size is too Large. Can't Add this Array. Out of Range");
    
    std::vector<int>::iterator it = this->array.begin() + position;
    this->array.insert(it, Array.begin(), Array.end());
    
    return ;
}

signed long Span::shortestSpan(void)
{
    if (this->array.size() == 0 || this->array.size() == 1)
        throw std::out_of_range("Can't Calculate Distance. You need more than 2 Elements.");
    signed long min = 0;
    signed long distance = 0;
    for (size_t i = 0; i < (this->array.size() - 1); ++i)
    {
        distance = std::abs(this->array[i] - this->array[i + 1]);
        if (distance < min || i == 0)
            min = distance;
    }
    return (min);
}

signed long Span::longestSpan(void)
{
    if (this->array.size() == 0 || this->array.size() == 1)
        throw std::out_of_range("Can't Calculate Distance. You need more than 2 Elements.");
    signed long max = 0;
    signed long distance = 0;
    for (size_t i = 0; i < (this->array.size() - 1); ++i)
    {
        distance = std::abs(this->array[i] - this->array[i + 1]);
        if (distance > max || i == 0)
            max = distance;
    }
    return (max);
}



std::ostream &operator<<(std::ostream &os, const Span &sp) 
{
    for (size_t i = 0; i < sp.get_array().size(); ++i)
        os << sp[i] << ", ";
    return os;
}