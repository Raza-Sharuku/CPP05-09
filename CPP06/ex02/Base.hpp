/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:02:27 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/14 18:04:02 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


class Base
{
    public:
        // デストラクタ
        virtual ~Base(void);
};

Base            *generate(void);
void            identify(Base* p);
void            identify(Base& p);


#endif