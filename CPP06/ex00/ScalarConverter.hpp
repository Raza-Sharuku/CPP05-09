/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:02 by razasharuku       #+#    #+#             */
/*   Updated: 2024/03/19 10:07:18 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string.h>
#include <exception>
#include <iomanip>

class ScalarConverter
{
    private:
        // コンストラクタ
        ScalarConverter();
        // コピーコンストラクタ
        ScalarConverter(const ScalarConverter& other);
    public:
        // コピー代入演算子
        ScalarConverter &operator=(const ScalarConverter& other);
        // デストラクタ
        ~ScalarConverter(void);
        // メンバ変数
        static void         convert(std::string str);
};



#endif