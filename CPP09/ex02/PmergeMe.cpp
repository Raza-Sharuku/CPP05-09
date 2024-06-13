/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:59:30 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/13 11:53:24 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(std::vector<int>& vec)
{
    this->vec_arr = vec;
    this->deque_arr = std::deque<int>(vec.begin(), vec.end());

    std::cout << "vector<int> : ";
    for (std::vector<int>::iterator it = this->vec_arr.begin(); it != this->vec_arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "deque<int> : ";
    for (std::deque<int>::iterator it = this->deque_arr.begin(); it != this->deque_arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    merge_insertion_sort_vec();
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


void PmergeMe::insertion_sort_vec()
{

}

void PmergeMe::merge_insertion_sort_vec()
{
    int size_arr = this->vec_arr.size();

    // ペアを作る
    std::vector<std::pair<int,int> > pairs;
    for (int i = 0; i < size_arr; i +=2)
    {
        if (i + 1 < size_arr)
            pairs.push_back(std::make_pair(this->vec_arr[i], this->vec_arr[i + 1]));
        else 
            pairs.push_back(std::make_pair(this->vec_arr[i], -1));
    }

    // firstに大きい値がくるようにする
    std::vector<int> big_num;
    for (unsigned long i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].second == -1 || pairs[i].first > pairs[i].second)
            big_num.push_back(pairs[i].first);
        else 
            big_num.push_back(pairs[i].second);
    }

    std::cout << "vector<int> big_num : ";
    for (std::vector<int>::iterator it = big_num.begin(); it != big_num.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return ;

}

