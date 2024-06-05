/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:55:23 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/05 16:02:50 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[31m" << '\n' << "Error: bad argument"  << "\033[0m" << '\n' << std::endl;
		return(0);
	}

	try
	{

	}
	catch(const std::exception& e)
	{
		std::cout << "\033[31m" << '\n' << e.what() << '\n'  << "\033[0m" << std::endl;
		return (0);
	}
	

    return 0;
}

// __attribute__((destructor))
// static void destructor() 
// {
//     system("leaks -q btc");
// }


