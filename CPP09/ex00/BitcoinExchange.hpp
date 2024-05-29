/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:16:24 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/29 17:44:44 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BITCOIN_EXCHANGE_HPP
# define _BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stack>
#include <map>
#include <list>
#include <deque>
#include <fstream>
#include <sstream>
#include <string>


class BitcoinExchange
{
    private:
        // data.csv用のデータを格納する配列が必要
        std::map<std::string, int>  data;
        
    public:
        // コンストラクタたち
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange(void);

        // メンバ関数
        std::map<std::string, int>  get_data(void);
        void                        input_data_csv(const std::string &data_csv);
        void                        printData() const ;
        




};


#endif