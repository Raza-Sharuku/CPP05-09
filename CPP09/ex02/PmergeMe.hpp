/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:57:58 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/13 11:21:08 by razasharuku      ###   ########.fr       */
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
        PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        std::vector<int>    vec_arr;
        std::deque<int>     deque_arr;
        time_t              vec_time;
        time_t              deque_time;

    public:
        // コンストラクターず
        PmergeMe(std::vector<int>& vec);
        ~PmergeMe(void);

        // メンバ関数
        void    insertion_sort_vec();
        void    merge_insertion_sort_vec();
        void    insertion_sort_deque();
        void    merge_insertion_sort_deque();

};


#endif