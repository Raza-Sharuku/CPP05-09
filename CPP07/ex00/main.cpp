/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:24:39 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/21 19:41:23 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void) 
{   
    std::cout << "\n --------------------------------\n"<< std::endl;
    int a = 2;
    int b = 3;
    std::cout << "      a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "->    ";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::cout << "\n --------------------------------\n"<< std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "      c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "->    ";
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    std::cout << "\n --------------------------------\n"<< std::endl;

    float  e = 1.0053f;
    float  f = 3.0005f;
    std::cout << "      e = " << e << ", f = " << f << std::endl;
    std::cout << "->    ";
    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
    std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;

    std::cout << "\n --------------------------------\n"<< std::endl;

    double  g = 1.0053;
    double  h = 3.0005;
    std::cout << "      g = " << g << ", h = " << h << std::endl;
    std::cout << "->    ";
    ::swap(g, h);
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min( g, h ) = " << ::min(g, h) << std::endl;
    std::cout << "max( g, h ) = " << ::max(g, h) << std::endl;




    std::cout << "\n --------------------------------"<< std::endl;
    return 0;
}