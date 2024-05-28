/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:05:36 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/28 10:53:21 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "\033[32m" << "++++++++++++++++++ test start 1 ++++++++++++++++\n" << "\033[0m" << std::endl;

    Span A(100);
    
    try
    {
        A.addNumber(10);
        A.addNumber(11);
        A.addNumber(12);
        std::cout << A[0] << std::endl;
        std::cout << A[1] << std::endl;
        std::cout << A[2] << std::endl;
        std::cout << A[4] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << '\n' << e.what() << '\n' << "\033[0m";
    }

	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 1 +++++++++++++++" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "++++++++++++++++++ test start 2 ++++++++++++++++\n" << "\033[0m" << std::endl;

    Span B(1000);
    try
    {
        for (int i = 0; i < 1000; i++)
            B.addNumber(i);
        std::cout << "array()      = { " << B << "}" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << '\n' << e.what() << '\n' << "\033[0m";
    }


	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 2 +++++++++++++++\n" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "++++++++++++++++++ test start 3 ++++++++++++++++\n" << "\033[0m" << std::endl;
    Span sp = Span(5);
    
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(18);
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << '\n' << e.what() << '\n' << "\033[0m";
    }

    std::cout << "array()      = { " << sp << "}" << std::endl;

    std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan  = " << sp.longestSpan() << std::endl;

    sp.set_array_value(1, 1000);

    std::cout << "array()      = { " << sp << "}" << std::endl;
    std::cout << "array()[1]   = " << sp.get_array()[1] << std::endl;
    std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan  = " << sp.longestSpan() << std::endl;
    
	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 3 +++++++++++++++\n" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "++++++++++++++++++ test start 4 ++++++++++++++++\n" << "\033[0m" << std::endl;

    Span C = Span(10);
    // この配列を編集して追加を確認してください。
    int Array_list[] = {23, 34, 21, 45, 56, 67, 78, 98};

    // 要素数の計算して末尾のポインタを取得している。vectorのコンストラクタを使用して、配列の先頭と末尾のポインタを渡して、
    std::vector<int> Array(Array_list, Array_list + sizeof(Array_list) / sizeof(Array_list[0]));

    try
    {
        C.addNumber(1111);
        C.addNumber(2222);
        C.addNumber(3333);
        C.addNumber(4444);
        C.add_number_at_once(Array, 2);
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << '\n' << e.what() << '\n' << "\033[0m";
    }
    std::cout << "array()      = { " << C << "}" << std::endl;
    std::cout << "array()[1]   = " << C.get_array()[1] << std::endl;
    std::cout << "shortestSpan = " << C.shortestSpan() << std::endl;
    std::cout << "longestSpan  = " << C.longestSpan() << std::endl;
    std::cout << "Array_Size   = " << C.get_array().size() << std::endl;


	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 4 +++++++++++++++\n" << "\033[0m" << std::endl;

    return 0;
}

__attribute__((destructor))
static void destructor() 
{
    system("leaks -q ex");
}