/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:05:36 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/26 09:20:14 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	
	if (argc != 2)
	{
		std::cerr << "\033[31m" << "Error: could not open file.\n" << "\033[0m" << std::endl;
		return (0);
	}
	try
	{
		std::ifstream input_file(argv[1]);
		if (!input_file)
			throw std::invalid_argument("Error: could not open file.");
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << e.what() << '\n'  << "\033[0m" << std::endl;
		return (0);
	}
	
	BitcoinExchange btc;
	try
	{
		btc.collect_data_csv("data.csv");
		btc.calculate_value(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << e.what() << '\n'  << "\033[0m" << std::endl;
	}

    return 0;
}

// __attribute__((destructor))
// static void destructor() 
// {
//     system("leaks -q btc");
// }
