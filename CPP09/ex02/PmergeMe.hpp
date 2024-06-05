/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:57:58 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/05 16:28:26 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PMERGE_ME_HPP
# define _PMERGE_ME_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <string>
#include <sstream>
#include <stack>



class PmergeMe
{
    private:
        PmergeMe(void);
        
    public:
        // コンストラクターズ
        PmergeMe(const std::string &str);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe(void);

        // メンバ関数
};


#endif