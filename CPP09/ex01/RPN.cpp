/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:34 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/11 10:36:08 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const std::string &str)
{
    std::istringstream  iss(str);
    int                 calculated_value;
    std::string         token;

    try
    {
        while (std::getline(iss, token, ' '))
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                calculated_value = calculate_stack(token);
                this->rpn_stack.push(calculated_value);
            }
            else 
            {
                int num = 0;
                std::istringstream num_iss(token);
                num_iss >> num;
                this->rpn_stack.push(num);
            }
        }
    }
    catch(const std::exception& e)
    {
		throw ;
    }
    result = this->rpn_stack.top();
    return ;
}

RPN::RPN(const RPN &other)
{
    *this = other;
    return ;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->rpn_stack = other.rpn_stack;
        this->result = other.result;
    }
    return (*this);
}

RPN::~RPN(void)
{
}


void RPN::printStack()
{
    std::stack<int> temp_stack = rpn_stack;
    while (!temp_stack.empty()) 
    {
        std::cout << temp_stack.top() << " ";
        temp_stack.pop();
    }
    std::cout << std::endl;
}


int RPN::calculate_stack(std::string token)
{
    if (this->rpn_stack.size() < 2)
        throw std::invalid_argument("Error: Invalid format of RPN");
    
    int left_side = 0;
    int right_side = 0;
    size_t calculated_value = 0;

    right_side = this->rpn_stack.top();
    this->rpn_stack.pop();
    left_side = this->rpn_stack.top();
    this->rpn_stack.pop();

    if (token == "+")
        calculated_value = left_side + right_side;
    else if (token == "-")
        calculated_value = left_side - right_side;
    else if (token == "*")
        calculated_value = left_side * right_side;
    else if (token == "/")
    {
        if (right_side == 0)
            throw std::logic_error("Error: Can't divide by 0");
        calculated_value = left_side / right_side;
    }
    else 
        throw std::invalid_argument("Error: Bad operator");

    if (token == "+" && (static_cast<int>(calculated_value) < left_side || static_cast<int>(calculated_value) < right_side))
        throw std::out_of_range("Error: Overflow");
    else if (token == "-" && static_cast<int>(calculated_value) > left_side)
        throw std::out_of_range("Error: Underflow");
    else if (token == "*" && (left_side != 0 && static_cast<int>(calculated_value) / left_side != right_side))
        throw std::out_of_range("Error: Overflow");

    return (calculated_value);
}

int RPN::get_result(void)
{
    return (this->result);
}

