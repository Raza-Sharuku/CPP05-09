/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:20:20 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/14 18:14:21 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// #include "Base.hpp"

Base::~Base()
{

}

Base    *generate(void)
{
    Base*	p;

    srand((unsigned)time(NULL));    
    int num = std::rand() % 3;
    
    if (num == 0)
        p = new A;
    else if (num == 1)
        p = new B;
    else if (num == 2)
        p = new C;
    else 
        std::cout << "Something wrong with this code!!" << std::endl;

    return (p);
}


void    identify(Base* p)
{
    std::cout << "Actual type of the object pointed" << std::endl;
    
    if (dynamic_cast<A*>(p))
        std::cout << "Class A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "Class C" << std::endl;
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
		std::cout << "A" << std::endl;
	} 
    catch (std::exception & e)
    {
	    try 
        {
            b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } 
        catch (std::exception & e) 
        {
            try 
            {
                c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } 
            catch (std::exception & e)
            {
                std::cout << "None of A, B, C class type!!" << std::endl;
            }
        }
    }
    return ;
}

