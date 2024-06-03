/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:16:24 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/03 11:15:53 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BITCOIN_EXCHANGE_HPP
# define _BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <map>


class BitcoinExchange
{
    private:
        // data.csv用のデータを格納する配列が必要
        std::map<std::string, float>  database;
        
    public:
        // コンストラクタたち
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange(void);

        // メンバ関数
        void                        collect_data_csv(const std::string &data_csv);
        void                        calculate_value(const std::string &input);
};


#endif