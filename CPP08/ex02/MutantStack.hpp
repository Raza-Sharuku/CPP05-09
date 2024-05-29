/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:16:24 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/28 17:32:53 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MUTANT_STACK_HPP
# define _MUTANT_STACK_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stack>
#include <deque>


template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        // コンストラクタたち
        MutantStack(void);
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack(void);

        // イテレータ
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin(void);
        iterator end(void);

        const_iterator begin(void) const;
        const_iterator end(void) const;
    
};

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{
};

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
    if (this != &other)
    {
        std::stack<T>::operator=(other);
    }
    return (*this);
};

template <typename T>
MutantStack<T>::~MutantStack(void)
{
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return (this->c.begin());
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return (this->c.end());
};

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
    return (this->c.begin());
};

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void)const
{
    return (this->c.end());
};


#endif