/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:02 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/15 17:43:30 by razasharuku      ###   ########.fr       */
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
        // []演算子
        T &operator[](unsigned int index);

        // メンバ関数
        unsigned int size() const;


};


#endif