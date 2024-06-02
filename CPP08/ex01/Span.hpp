/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:16:24 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/01 15:43:49 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <iterator>


class Span
{
    private:
        // N個の個数を入れる
        unsigned int m_maxnum;
        // 配列
        std::vector<int> array;

    public:
        Span(unsigned int N);
        Span(Span const &other);
        Span &operator=(const Span &other);
        ~Span(void);

        // []添字演算子
        int &operator[](unsigned int i);
        const int &operator[](unsigned int i) const;

        // getter setter
        const std::vector<int>  get_array() const;
        void                    set_array_value(int index, int num);

        // member functions
        void addNumber(int num);
        void add_number_at_once(const std::vector<int>& Array);
        size_t shortestSpan(void);
        size_t longestSpan(void);

};

std::ostream &operator<<(std::ostream &os, const Span &arr );

#endif