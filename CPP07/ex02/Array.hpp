/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:02 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/22 15:49:06 by razasharuku      ###   ########.fr       */
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
        T &operator[](unsigned int i) const;

        // メンバ関数
        unsigned int size() const;


};


// 空のArrayを作る必要あり。NULLだと空のArrayはできていないので❌
template <typename T>
Array<T>::Array(void) : elements(new T[1]), length(0)
{    
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), length(n)
{
}

template <typename T>
Array<T>::Array(const Array &other) : elements(new T[other.length]), length(other.length)
{
    *this = other;
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
T &Array<T>::operator[](unsigned int i) const 
{
    if (i >= this->length) 
    {
        throw std::exception();
    }
    return this->elements[i];
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

template < typename T >
std::ostream &operator<<(std::ostream &os, const Array<T> &arr ) 
{
    for (unsigned int i = 0; i < arr.size(); i++ )
        os << arr[i] << " ";
    return os;
}


#endif