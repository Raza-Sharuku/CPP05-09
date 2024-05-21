/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:02 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/21 19:37:44 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>


template <typename T>
class Array
{
    private:
        T               *elements;
        unsigned int    length;

    public:
        // コンストラクタ
        Array(void);
        // コンストラクタ（nを引数にする）
        Array(unsigned int n);
        // コピーコンストラクタ
        Array(const Array &other);
        // コピー代入演算子
        Array &operator=(const Array &other);
        // デストラクタ
        ~Array(void);
        // []添字演算子
        T &operator[](unsigned int i);

        // メンバ関数
        unsigned int size() const;


};


// 空のArrayを作る必要あり。NULLだと空のArrayはできていないので❌
template <typename T>
Array<T>::Array(void) : elements(NULL), length(0)
{    
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), length(n)
{    
}

template <typename T>
Array<T>::Array(const Array &other) : elements(new T[other.length]), length(other.length)
{
    unsigned int i = 0;
    while (i < length)
    {
        this->elements[i] = other.elements[i];
        i++;
    }
    return ;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] elements;
        this->length = other.length;
        elements = new T[length];
        unsigned int i = 0;
        while (i < length)
        {
            this->elements[i] = other.elements[i];
            i++;
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
    delete[] elements;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= this->length)
    {
        throw std::exception();
    }
    return this->elements[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (length);
}


#endif