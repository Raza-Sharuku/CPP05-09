/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:24:39 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/17 11:14:08 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data        *new_data = NULL;
    uintptr_t   converted_uptr;
    Data        *converted_data;

    new_data = new Data;
    new_data->num = 100;
    new_data->str = "raza";

    // 新規で作成したDataの中身を表示する
    std::cout << "\033[1;33m" << "++++++++++++++++++ test start ++++++++++++++++++++\n" << "\033[0m" << std::endl;
    std::cout << "new_data->num :" << new_data->num << std::endl;
    std::cout << "new_data->str :" << new_data->str << std::endl;
    std::cout << "new_data->num :" << &new_data->num << std::endl;
    std::cout << "new_data->str :" << &new_data->str << std::endl;
    std::cout << std::endl;

    // serializerでポインターをuintptr_t型の整数値に変換する。でその値を表示（数値からわかることは何もない）
    converted_uptr = Serializer::serialize(new_data);
    std::cout << "Serializer::serialize :" << converted_uptr << std::endl;
    std::cout << std::endl;

    // serializerでポインターをuintptr_t型の整数値に変換する。その値を表示
    converted_data = Serializer::deserialize(converted_uptr);
    std::cout << "Serializer::deserialize :" << converted_data << std::endl;
    std::cout << std::endl;

    // 実際に変換を２回して元の値に戻ったかどうかを確認する（アドレス値の比較）
    if (new_data == converted_data) 
    {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "converted_data->num :" << converted_data->num << std::endl;
        std::cout << "converted_data->str :" << converted_data->str << std::endl;
        std::cout << "converted_data->num :" << &converted_data->num << std::endl;
        std::cout << "converted_data->str :" << &converted_data->str << std::endl;
    } 
    else 
    {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }


    std::cout << std::endl;


    std::cout << "\033[1;33m" << "++++++++++++++++++ test end ++++++++++++++++++++\n" << "\033[0m" << std::endl;
    delete new_data;


    return (0);
}

__attribute__((destructor))
static void destructor() 
{
    system("leaks -q ex");
}


/*
reinterpret_castは、ポインタの値自体を別の型に変換するだけで、そのポインタが指し示すオブジェクトの構造や内容まで変換するわけではない
new_data->strは文字列データ"raza"を指すポインタで、その値はアドレス値として表示される

Serializer::serialize(&new_data)は、new_dataオブジェクトのアドレス値をuintptr_t型に変換して
Serializer::deserialize()は、そのuintptr_t値をData*型に変換している。これはnew_dataオブジェクトのアドレスを復元しているだけ

よって、converted_data_ptrはnew_dataオブジェクトと同じアドレス値を指しているけど、
converted_data_ptr->strは文字列データ"raza"のアドレス値を指している

*/ 