/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:51:07 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/24 13:25:17 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _R_P_N_HPP
# define _R_P_N_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <string>
#include <sstream>
#include <stack>




class RPN
{
    private:
        std::stack<int> rpn_stack;
        int             result;
        RPN(void);
        
    public:
        // コンストラクターズ
        RPN(const std::string &str);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN(void);

        // メンバ関数
        void        printStack();
        int         calculate_stack(std::string token);
        int         get_result(void);
};


#endif