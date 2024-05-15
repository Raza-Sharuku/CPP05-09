/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:24:39 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/15 14:41:41 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


int main() 
{
	std::cout << "\033[1;33m" << "++++++++++++++++++ test start 1 ++++++++++++++++\n" << "\033[0m" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    const size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    const size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "元のINT VALUE: ";
    iter(intArray, intLength, print<int>);
    std::cout << std::endl;

    iter(intArray, intLength, multiply_Two<int>);

    std::cout << "変更後のINT VALUE: ";
    iter(intArray, intLength, print<int>);
    std::cout << std::endl;

	std::cout << "\033[1;33m" << "\n++++++++++++++++++ test finish 1 +++++++++++++++" << "\033[0m" << std::endl;
	std::cout << "\033[1;36m" << "++++++++++++++++++ test start 2 ++++++++++++++++\n" << "\033[0m" << std::endl;


    std::cout << "元のDOUBLE VALUE: ";
    iter(doubleArray, doubleLength, print<double>);
    std::cout << std::endl;

    iter(doubleArray, doubleLength, multiply_Two<double>);

    std::cout << "変更後のDOUBLE VALUE: ";
    iter(doubleArray, doubleLength, print<double>);
    std::cout << std::endl;
	std::cout << "\033[1;36m" << "\n++++++++++++++++++ test finish 2 +++++++++++++++\n" << "\033[0m" << std::endl;

    return 0;
}