/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:25:29 by sraza             #+#    #+#             */
/*   Updated: 2024/03/28 10:18:48 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\033[1;34m" << "++++++++++++++++++ START ++++++++++++++++++++\n" << "\033[0m" << std::endl;
	try
    {
        std::cout << "\033[1;35m" << "+++++++++++++ TEST 1 _START ++++++++++\n" << "\033[0m" << std::endl;
        Bureaucrat raza("raza",33);
        Bureaucrat Tom("Tom",150);
        Bureaucrat Harry("Professor",1);

        
        std::cout << raza << std::endl;
        std::cout << Tom << std::endl;
        std::cout << Harry << std::endl;
        std::cout << "\033[1;35m" << "+++++++++++++ TEST 1 _END ++++++++++\n" << "\033[0m" << std::endl;

        std::cout << "\033[1;36m" << "+++++++++++++ TEST 2 _START ++++++++++\n" << "\033[0m" << std::endl;
        Harry.increase_grade(1);
        std::cout << Harry << std::endl;
        std::cout << "\033[1;36m" << "+++++++++++++ TEST 2 _END ++++++++++\n" << "\033[0m" << std::endl;
	}
    catch(std::exception& e)
    {
		std::cout << e.what() << std::endl;
    }

	try
    {
        std::cout << "\033[1;35m" << "+++++++++++++ TEST 2-1 _START ++++++++++\n" << "\033[0m" << std::endl;
        Bureaucrat *raza = new Bureaucrat("raza",33);
        Bureaucrat *Tom = new Bureaucrat("Tom",150);
        Bureaucrat *Harry = new Bureaucrat("Harry",1);

        
        std::cout << *raza << std::endl;
        std::cout << *Tom << std::endl;
        std::cout << *Harry << std::endl;

        delete raza;
        delete Tom;
        delete Harry;
        std::cout << "\033[1;35m" << "+++++++++++++ TEST 2-1 _END ++++++++++\n" << "\033[0m" << std::endl;

        std::cout << "\033[1;36m" << "+++++++++++++ TEST 2-2 _START ++++++++++\n" << "\033[0m" << std::endl;
        Bureaucrat *Potter = new Bureaucrat("Potter",0);
        delete Potter;
        std::cout << Potter << std::endl;
	}
    catch(std::exception& e)
    {
		std::cout << e.what() << std::endl;
        std::cout << "\033[1;36m" << "+++++++++++++ TEST 2-2 _END ++++++++++\n" << "\033[0m" << std::endl;
    }    
    std::cout << "\033[1;34m" << "++++++++++++++++++ END ++++++++++++++++++++\n" << "\033[0m" << std::endl;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q ex");
}