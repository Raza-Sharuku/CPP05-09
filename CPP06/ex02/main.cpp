/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:24:39 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/15 10:07:41 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	Base *p;

	srand((unsigned)time(NULL));
	std::cout << "\033[1;33m" << "++++++++++++++++++ test start 1 ++++++++++++++++++++\n" << "\033[0m" << std::endl;

	p = generate();
	if (p == NULL)
	{
    	std::cout << "COULDN'T GENERATE P !!"  << std::endl;
		return (0);
	}
    std::cout << "P is successfully generated !!\n"  << std::endl;
    
    std::cout << "-----------------------\n"  << std::endl;
	identify(p);
    std::cout << "\n-----------------------\n"  << std::endl;
	identify(*p);

    std::cout << "\033[1;33m" << "\n++++++++++++++++++ test end +++++++++++++++++++++++\n" << "\033[0m" << std::endl;

	delete p;

	std::cout << "\033[1;33m" << "++++++++++++++++++ test start 2 +++++++++++++++++++\n" << "\033[0m" << std::endl;
	Base *q = new Base;
	
    std::cout << "Test of Base class(which none of A,B,C) !!\n"  << std::endl;
    std::cout << "-----------------------\n"  << std::endl;
	identify(q);
    std::cout << "\n-----------------------\n"  << std::endl;
	identify(*q);
	
	delete q;
    std::cout << "\033[1;33m" << "\n++++++++++++++++++ test end ++++++++++++++++++++++\n" << "\033[0m" << std::endl;
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q ex");
}