/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:20:20 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/15 10:06:26 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"

Base::~Base()
{
}

Base    *generate(void)
{
    Base*	p;
    int num = std::rand() % 3;
        
    if (num == 0)
        p = new A;
    else if (num == 1)
        p = new B;
    else if (num == 2)
        p = new C;
    else 
    {
        std::cout << "Something wrong with this code!!" << std::endl;
        p = NULL;
    }

    return (p);
}


void    identify(Base* p)
{
    
    if (p == NULL)
    {
    	std::cout << "P is NULL!!"  << std::endl;
		return ;
    }
    if (dynamic_cast<A*>(p))
        std::cout << "Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C" << std::endl;
    else 
        std::cout << "None of A, B, C class type!!" << std::endl;

    return ;
}


void    identify(Base& p)
{
	A a;
	B b;
	C c;

    try 
    {
		a = dynamic_cast<A&>(p);
		std::cout << "Class A" << std::endl;
	} 
    catch (std::exception & e)
    {
	    try 
        {
            b = dynamic_cast<B&>(p);
            std::cout << "Class B" << std::endl;
        } 
        catch (std::exception & e) 
        {
            try 
            {
                c = dynamic_cast<C&>(p);
                std::cout << "Class C" << std::endl;
            } 
            catch (std::exception & e)
            {
                std::cout << "None of A, B, C class type!!" << std::endl;
            }
        }
    }
    return ;
}

