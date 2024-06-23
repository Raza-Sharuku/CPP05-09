/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_up.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:59:30 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/23 17:30:39 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool is_sorted(std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
            break;
        if (vec[i] > vec[i + 1])
            return (false);
    }
    return (true);

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

PmergeMe::PmergeMe(std::vector<int>& vec)
{
    this->vec_arr = vec;
    this->deque_arr = std::deque<int>(vec.begin(), vec.end());

    // std::cout << "std::vector<int> : ";
    // for (std::vector<int>::iterator it = this->vec_arr.begin(); it != this->vec_arr.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "deque<int> : ";
    // for (std::deque<int>::iterator it = this->deque_arr.begin(); it != this->deque_arr.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;


    std::clock_t start = std::clock();
    this->vec_arr = fordJohnson_Sort(this->vec_arr);
    std::clock_t end = std::clock();
    double time_ms_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

    std::cout << "Time to process a range of " << this->vec_arr.size() << " elements with std::[vector] : "<< time_ms_vec << "ms" << std::endl;







    if (!is_sorted(this->vec_arr))
        std::cout << "\033[31m" << '\n' << "NOT SORTED \n"  << "\033[0m" << std::endl;
    else 
        std::cout << "\033[32m" << '\n' << "SORTED \n"  << "\033[0m" << std::endl;


    return ;
}

std::vector<int>    PmergeMe::jacobsthal(int n)
{
    std::vector<int> seq;
    seq.reserve(n);
    seq.push_back(1);
    if (n > 1)
        seq.push_back(1);
    for (int i = 2; i < n; i++)
        seq.push_back(seq[i - 1] + 2 * seq[i - 2]);

    for (int i = 0; i < n; i++) 
        seq[i] = 2 * seq[i];


    return (seq);
}

std::vector<std::vector<int> >     PmergeMe::make_groups(std::vector<int>& first_group)
{
    std::vector<std::vector<int> > groups;

    if (first_group.size() < 2)
    {
        groups.push_back(std::vector<int>(first_group.begin(), first_group.end()));
        return (groups);
    }

    std::vector<int> sizes;
    sizes = jacobsthal(first_group.size());

    size_t start = 0;
    for (std::vector<int>::iterator it = sizes.begin(); it != sizes.end(); ++it) 
    {
        if (start >= first_group.size()) 
            break;
        int end = std::min(start + *it, static_cast<size_t>(first_group.size()));
        groups.push_back(std::vector<int>(first_group.begin() + start, first_group.begin() + end));
        start += *it;
    }
    for (std::vector<std::vector<int> >::iterator it = groups.begin(); it != groups.end(); ++it) 
        std::reverse(it->begin(), it->end());
    
    return (groups);
}

int     PmergeMe::binarySearch_vec(const std::vector<int>& arr, int start, int end, int target)
{
    while (start < end) 
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    return (start);
}


std::vector<std::pair<int, int> > PmergeMe::createPairs(std::vector<int>& arr)
{
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if(arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else 
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    return (pairs);
}

std::vector<int>    PmergeMe::fordJohnson_Sort(std::vector<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return (arr);

    int straggler =  -1;
    if (n % 2 == 1)
    {
        straggler =  arr[n - 1];
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs = createPairs(arr);

    std::vector<int> S;
    std::vector<int> first_value;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        S.push_back(pairs[i].second);
        first_value.push_back(pairs[i].first);
    }
    std::cout << std::endl;
    
    S = fordJohnson_Sort(S);

    std::cout << "after recursive : S : ";
    for (std::vector<int>::iterator it = S.begin(); it != S.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int> > groups;    
    groups = make_groups(first_value);


    if (groups.size() > 1)
    {
        for (size_t i = 0; i < groups.size(); i++) 
        {
            for (size_t j = 0; j < groups[i].size(); j++) 
            {
                int insertPos = binarySearch_vec(S, 0, S.size() - 1, groups[i][j]);
                S.insert(S.begin() + insertPos, groups[i][j]);
                std::cout << "groups: S inserting values  : ";
                for (std::vector<int>::iterator it = S.begin(); it != S.end(); ++it)
                    std::cout << *it << " ";
                std::cout << std::endl;
            }
        }
    }
    else 
    {    
        for (size_t i = 0; i < pairs.size(); i++)
        {
            int insertPos = binarySearch_vec(S, 0, S.size(), pairs[i].first);
            S.insert(S.begin() + insertPos, pairs[i].first);
            std::cout << "pairs: S inserting values  : ";
            for (std::vector<int>::iterator it = S.begin(); it != S.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
    }

    if (straggler != -1)
    {
        int insertPos = binarySearch_vec(S, 0, S.size(), straggler);
        S.insert(S.begin() + insertPos, straggler);
        std::cout << "straggler: S inserting values  : ";
        for (std::vector<int>::iterator it = S.begin(); it != S.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Last check of JFMI-> S  : ";
    for (std::vector<int>::iterator it = S.begin(); it != S.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    return (S);
}

int     PmergeMe::binarySearch_deq(const std::deque<int>& arr, int start, int end, int target)
{
    while (start < end) 
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    return (start);
}


std::deque<std::pair<int, int> > PmergeMe::createPairs_deq(std::deque<int>& arr)
{
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if(arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else 
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    return (pairs);
}
