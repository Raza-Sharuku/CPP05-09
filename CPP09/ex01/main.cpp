/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:46 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/05 13:29:13 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


static bool check_argument(const std::string &str)
{
	if (!isdigit(str[0]))
		return (false);
	if (str[str.length() - 1] == ' ')
		return (false);

	size_t digits_count = 0;
	size_t operator_count = 0;

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
		if (str[str.length() - 1])
		{
			if (str[i] == ' ' && !isdigit(str[i + 1]) && str[i + 1] != '+' && str[i + 1] != '-' && str[i + 1] != '*' && str[i + 1] != '/')
				return (false);
		}
		if (isdigit(str[i]))
			digits_count++;
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			operator_count++;
	}
	if (digits_count != operator_count + 1)
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 2 || !check_argument(argv[1]))
	{
		std::cout << "\033[31m" << '\n' << "Error: bad argument"  << "\033[0m" << '\n' << std::endl;
		return(0);
	}

	try
	{
		RPN rpn(argv[1]);
		std::cout << "\033[32m" << "\nCalculated Result: " << rpn.get_result() << '\n' << "\033[0m" << std::endl;
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


