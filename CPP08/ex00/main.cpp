/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:05:36 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/01 13:29:35 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main()
{
	std::cout << "\033[31m" << "++++++++++++++++++ test start 1 ++++++++++++++++\n" << "\033[0m" << std::endl;

    std::vector<int> int_array(5);
    int_array.push_back(100);
    int_array.push_back(101);
    int_array.push_back(102);
    int_array.push_back(103);
    int_array.push_back(104);
    try 
    {
        std::vector<int>::iterator it_1 = easyfind(int_array, 104);
        std::cout << *it_1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::vector<int>::iterator it_2 = easyfind(int_array, 1);
        std::cout << *it_2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\033[31m" << "\n++++++++++++++++++ test finish 1 +++++++++++++++" << "\033[0m" << std::endl;

	std::cout << "\033[32m" << "++++++++++++++++++ test start 2 ++++++++++++++++\n" << "\033[0m" << std::endl;
    
    std::vector<char> char_array(5);
    char_array.push_back('r');
    char_array.push_back('a');
    char_array.push_back('w');
    char_array.push_back('z');
    char_array.push_back('a');
    try 
    {
        std::vector<char>::iterator it_3 = easyfind(char_array, 'w');
        std::cout << *it_3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::vector<char>::iterator it_3 = easyfind(char_array, 'p');
        std::cout << *it_3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 2 +++++++++++++++\n" << "\033[0m" << std::endl;


    return 0;
}

// __attribute__((destructor))
// static void destructor() 
// {
//     system("leaks -q ex");
// }