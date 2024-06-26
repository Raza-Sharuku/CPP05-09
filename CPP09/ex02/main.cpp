/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:55:23 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/26 10:15:51 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


std::vector<int> make_list(char *argv[], int argc)
{
    std::vector<int> vec_arr;
    std::string str;
    int i = 1;

    while (i < argc)
    {
        str = static_cast<std::string>(argv[i]);
        std::istringstream iss(str);
        std::string token;

        while (iss >> token)
        {
            int num;
            std::istringstream token_stream(token);
            token_stream >> num;

            if (token_stream.fail() || !token_stream.eof())
                throw std::runtime_error("Error: Invalid argument.");
            if (num < 0)
                throw std::out_of_range("Error: Negative number.");

            vec_arr.push_back(num);
        }
        i++;
    }

    // vec_arrの内容を確認
    // std::cout << "\033[35m" << "-------------->         ";
    // for (std::vector<int>::iterator it = vec_arr.begin(); it != vec_arr.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\033[0m"  << std::endl << std::endl;

    return (vec_arr);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "\033[31m" << '\n' << "Error: bad argument"  << "\033[0m" << '\n' << std::endl;
		return(0);
	}

	try
	{
        std::vector<int> vec_arr;
	    vec_arr = make_list(argv, argc);

        PmergeMe my_merge(vec_arr);

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
//     system("leaks -q PmergeMe");
// }


