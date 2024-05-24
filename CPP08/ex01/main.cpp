/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:05:36 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/24 15:08:26 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main()
{
	std::cout << "\033[31m" << "++++++++++++++++++ test start 1 ++++++++++++++++\n" << "\033[0m" << std::endl;

    std::array<int, 5> int_array = {3, 1, 4, 2, 0};
    try 
    {
        std::cout << easyfind(int_array, 0) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::cout << easyfind(int_array, 6) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\033[31m" << "\n++++++++++++++++++ test finish 1 +++++++++++++++" << "\033[0m" << std::endl;

	std::cout << "\033[32m" << "++++++++++++++++++ test start 2 ++++++++++++++++\n" << "\033[0m" << std::endl;
    std::array<double, 5> double_array = {3.5, 1.5, 4.0, 2.5, 0.6};
    try 
    {
        std::cout << easyfind(double_array, (int)4.5) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::cout << easyfind(double_array, (int)10.2) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 2 +++++++++++++++\n" << "\033[0m" << std::endl;

	std::cout << "\033[32m" << "++++++++++++++++++ test start 3 ++++++++++++++++\n" << "\033[0m" << std::endl;
    std::array<char, 5> char_array = {'r','a', 'w', 'z', 'a'};
    try 
    {
        std::cout << easyfind(char_array, 'a') << std::endl;
        std::cout << easyfind(char_array, 97) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::cout << easyfind(char_array, 'p') << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 3 +++++++++++++++\n" << "\033[0m" << std::endl;


    return 0;
}

__attribute__((destructor))
static void destructor() 
{
    system("leaks -q ex");
}