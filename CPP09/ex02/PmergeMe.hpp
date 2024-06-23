/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:57:58 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/23 18:21:58 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PMERGE_ME_HPP
# define _PMERGE_ME_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>



class PmergeMe
{
    private:
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        std::vector<int>    vec_arr;
        std::deque<int>     deque_arr;

        // VECTOR
        std::vector<int>                    jacobsthal_vec(int n);
        int                                 binarySearch_vec(const std::vector<int>& arr, int start, int end, int target);
        std::vector<int>                    fordJohnson_Sort_vec(std::vector<int>& arr);
        std::vector<std::pair<int, int> >   createPairs(std::vector<int>& arr);
        std::vector<std::vector<int> >      make_groups_vec(std::vector<int>& first_group);

        // DEQUE
        std::deque<int>                     jacobsthal_deq(int n);
        int                                 binarySearch_deq(const std::deque<int>& arr, int start, int end, int target);
        std::deque<int>                     fordJohnson_Sort_deq(std::deque<int>& arr);
        std::deque<std::pair<int, int> >    createPairs_deq(std::deque<int>& arr);
        std::deque<std::deque<int> >        make_groups_deq(std::deque<int>& first_group);

    public:
        // コンストラクターず
        PmergeMe(std::vector<int>& vec);
        ~PmergeMe(void);

        // メンバー関数
        void                                print_sort_result(double time_ms_vec, double time_ms_deq, std::vector<int>& vec);

};


#endif