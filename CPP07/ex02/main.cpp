/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:24:39 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/16 10:08:48 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int main() 
{
	std::cout << "\033[31m" << "++++++++++++++++++ test start 1 ++++++++++++++++\n" << "\033[0m" << std::endl;

    Array<double> arr1;
    std::cout << "arr1 size: " << arr1.size() << std::endl;
	std::cout << "\033[31m" << "\n++++++++++++++++++ test finish 1 +++++++++++++++" << "\033[0m" << std::endl;


	std::cout << "\033[32m" << "++++++++++++++++++ test start 2 ++++++++++++++++\n" << "\033[0m" << std::endl;
    Array<int> arr2(5);
    std::cout << "arr2 size: " << arr2.size() << std::endl;
    for (unsigned int i = 0; i < arr2.size(); ++i) 
    {
        arr2[i] = i;
    }
    for (unsigned int i = 0; i < arr2.size(); ++i) 
    {
        std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
    }
	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 2 +++++++++++++++\n" << "\033[0m" << std::endl;


	std::cout << "\033[33m" << "++++++++++++++++++ test start 3 ++++++++++++++++\n" << "\033[0m" << std::endl;
    Array<int> arr3(arr2);
    std::cout << "arr3 size: " << arr3.size() << std::endl;
    for (unsigned int i = 0; i < arr3.size(); ++i) 
    {
        std::cout << "arr3[" << i << "]: " << arr3[i] << std::endl;
    }
	std::cout << "\033[33m" << "\n++++++++++++++++++ test finish 3 +++++++++++++++\n" << "\033[0m" << std::endl;


	std::cout << "\033[34m" << "++++++++++++++++++ test start 4 ++++++++++++++++\n" << "\033[0m" << std::endl;
    Array<int> arr4;
    arr4 = arr2;
    std::cout << "arr4 size: " << arr4.size() << std::endl;
    for (unsigned int i = 0; i < arr4.size(); ++i) 
    {
        std::cout << "arr4[" << i << "]: " << arr4[i] << std::endl;
    }
	std::cout << "\033[34m" << "\n++++++++++++++++++ test finish 4 +++++++++++++++\n" << "\033[0m" << std::endl;


	std::cout << "\033[35m" << "++++++++++++++++++ test start 5 ++++++++++++++++\n" << "\033[0m" << std::endl;
    Array<double> arr5(10);
    std::cout << "arr5 size: " << arr5.size() << std::endl;
    double d = 0.05;
    for (unsigned int i = 0; i < arr5.size(); ++i) 
    {
        arr5[i] = d;
        d += 0.5;
    }
    for (unsigned int i = 0; i < arr5.size(); ++i) 
    {
        std::cout << "arr5[" << i << "]: " << arr5[i] << std::endl;
    }
	std::cout << "\033[35m" << "\n++++++++++++++++++ test finish 5 +++++++++++++++\n" << "\033[0m" << std::endl;


	std::cout << "\033[36m" << "++++++++++++++++++ test start 6 ++++++++++++++++\n" << "\033[0m" << std::endl;
    try 
    {
        arr2[10] = 10;
    }
    catch (const std::exception& e)
    {
        std::cout << "Out of bounds access attempted." << std::endl;
    }
	std::cout << "\033[35m" << "\n++++++++++++++++++ test finish 5 +++++++++++++++\n" << "\033[0m" << std::endl;


    return 0;
}