/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:02:27 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/15 09:32:26 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <exception>


class Base
{
    public:
        // デストラクタ
        virtual ~Base(void);
};

class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};

Base            *generate(void);
void            identify(Base* p);
void            identify(Base& p);


#endif