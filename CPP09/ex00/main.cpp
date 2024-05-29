/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:05:36 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/29 17:39:38 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	
	std::cout << "\033[32m" << "++++++++++++++++++ test start 1 ++++++++++++++++\n" << "\033[0m" << std::endl;
	if (argc != 2)
	{
		std::cerr << "\033[31m" << "*** Bad input numbers of Arguments!! ***\n" << "\033[0m" << std::endl;
		return (1);
	}
	try
	{
		std::ifstream input_file(argv[1]);
		if (!input_file)
			throw std::invalid_argument("File couldn't Open. Error!! Invalid_Argument");
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << e.what() << '\n'  << "\033[0m" << std::endl;
	}
	
	BitcoinExchange btc;

	btc.input_data_csv("data.csv");
	std::cout << "\033[32m" << "++++++++++++++++++ debug ++++++++++++++++\n" << "\033[0m" << std::endl;
	btc.printData();
	







	
	std::cout << "\033[32m" << "++++++++++++++++++ test finish 1 ++++++++++++++++\n" << "\033[0m" << std::endl;

    return 0;
}

// __attribute__((destructor))
// static void destructor() 
// {
//     system("leaks -q btc");
// }