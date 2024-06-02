/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:24:38 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/01 16:39:34 by razasharuku      ###   ########.fr       */
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

void Span::add_number_at_once(const std::vector<int>& Array)
{
    std::vector<int>::iterator it = this->array.end();

    for (std::vector<int>::const_iterator it_arr = Array.begin(); it_arr != Array.end(); ++it_arr)
    {
        if (this->array.size() - 1 >= this->m_maxnum)
            throw std::out_of_range("Can't Add anymore. Out of Range");

        it = this->array.insert(it, *it_arr);
        ++it;
    }
    return;
}

size_t Span::shortestSpan(void)
{
    if (this->array.size() == 0 || this->array.size() == 1)
        throw std::out_of_range("Can't Calculate Distance. You need more than 2 Elements.");

    std::vector<int> sortedArray(this->array);
    std::sort(sortedArray.begin(), sortedArray.end());
    size_t min = 0;
    size_t distance = 0;

    for (size_t i = 0; i < (sortedArray.size() - 1); ++i)
    {
        if (static_cast<size_t>(sortedArray[i]) > static_cast<size_t>(sortedArray[i + 1]))
            distance = (static_cast<size_t>(sortedArray[i])) - (static_cast<size_t>(sortedArray[i + 1]));
        else 
            distance = (static_cast<size_t>(sortedArray[i + 1])) - (static_cast<size_t>(sortedArray[i]));

        if ((distance) < min || i == 0)
            min = (distance);
    }
    return (min);
}

size_t Span::longestSpan(void)
{
    if (this->array.size() == 0 || this->array.size() == 1)
        throw std::out_of_range("Can't Calculate Distance. You need more than 2 Elements.");
    
    std::vector<int> sortedArray(this->array);
    std::sort(sortedArray.begin(), sortedArray.end());
    size_t max = 0;

    max = static_cast<size_t>(sortedArray[sortedArray.size() - 1]) - static_cast<size_t>(sortedArray[0]);
    return (max);
}



std::ostream &operator<<(std::ostream &os, const Span &sp) 
{
    for (size_t i = 0; i < sp.get_array().size(); ++i)
        os << sp[i] << ", ";
    return os;
}