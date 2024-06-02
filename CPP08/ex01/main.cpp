/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:05:36 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/01 16:40:03 by razasharuku      ###   ########.fr       */
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

    Span B(100);
    try
    {
        for (int i = 0; i < 100; i++)
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

    try
    {
        std::cout << "array()      = { " << sp << "}" << std::endl;

        std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan  = " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << e.what() << '\n' << "\033[0m";
    }
    try
    {
        sp.set_array_value(1, 1000);
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << e.what() << '\n' << "\033[0m";
    }
    try
    {
        std::cout << "array()      = { " << sp << "}" << std::endl;
        std::cout << "array()[1]   = " << sp.get_array()[1] << std::endl;
        std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << e.what() << '\n' << "\033[0m";
    }
    try
    {
        std::cout << "longestSpan  = " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << e.what() << '\n' << "\033[0m";
    }
    
	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 3 +++++++++++++++\n" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "++++++++++++++++++ test start 4 ++++++++++++++++\n" << "\033[0m" << std::endl;

    Span C = Span(10);
    // この配列を編集して追加を確認してください。
    int Array_list[] = {INT_MAX,3,4,8,2,INT_MIN};

    // 要素数の計算して末尾のポインタを取得している。vectorのコンストラクタを使用して、配列の先頭と末尾のポインタを渡して、
    std::vector<int> Array(Array_list, Array_list + sizeof(Array_list) / sizeof(Array_list[0]));

    try
    {
        C.addNumber(100);
        C.addNumber(101);
        C.addNumber(102);
        C.addNumber(103);
        C.add_number_at_once(Array);
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << '\n' << e.what() << '\n' << "\033[0m";
    }
    std::cout << "array()      = { " << C << "}" << std::endl;
    std::cout << "array()[1]   = " << C.get_array()[1] << std::endl;
    std::cout << "Array_Size   = " << C.get_array().size() << std::endl;
    try
    {
        std::cout << "shortestSpan = " << C.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << e.what() << '\n' << "\033[0m";
    }
    try
    {
        std::cout << "longestSpan  = " << C.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31m" << e.what() << '\n' << "\033[0m";
    }
    


	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 4 +++++++++++++++\n" << "\033[0m" << std::endl;

    return 0;
}

// __attribute__((destructor))
// static void destructor() 
// {
//     system("leaks -q ex");
// }