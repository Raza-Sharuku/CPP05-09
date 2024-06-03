/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:46 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/03 15:21:19 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


static bool check_argument(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
			return (false);
		if (i + 1 < str.length())
		{
			if(isdigit(str[i]) && isdigit(str[i + 1]))
				return (false);
			if(isdigit(str[i]) && str[i + 1] != ' ')
				return (false);
		}
	}
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 2 || !check_argument(argv[1]))
	{
		std::cout << "Error: bad argument"  << std::endl;
		return(0);
	}
	RPN rpn;

	try
	{
		
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[31m" << e.what() << '\n'  << "\033[0m" << std::endl;
		return (0);
	}
	

    return 0;
}

// __attribute__((destructor))
// static void destructor() 
// {
//     system("leaks -q btc");
// }