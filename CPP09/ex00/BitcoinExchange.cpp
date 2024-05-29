/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:28:19 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/29 17:45:22 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
    return ;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->data = other.data;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

// --------------------------------------------------------------------------------------------------------------------------------- //
// ------------------------------                             ここから下が主な処理                       ------------------------------ //
// --------------------------------------------------------------------------------------------------------------------------------- //


// static std::string space_remover(std::string line)
// {

    

//     return (line);
// }


void BitcoinExchange::input_data_csv(const std::string &data_csv)
{
    std::ifstream file(data_csv);
    if (!file)
    {
        std::cerr <<  "Error : File couldn't open. " << data_csv << std::endl;
        return ;
    }
    
    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate")
    {
        std::cerr <<  "Error : File format is Wrong. " << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
        // スペースなどの無駄なものをとる処理を入れる

        std::istringstream  iss(line);
        std::string         date;
        float               exchangerate;

        if (std::getline(iss, date, ',') && iss >> exchangerate)
            (this->data)[date] = exchangerate;
    }
    file.close();
    return ;
}

void BitcoinExchange::printData() const
{
    std::map<std::string, int>::const_iterator it;
    for (it = (this->data).begin(); it != (this->data).end(); ++it) 
    {
        std::cout << "Date: " << it->first << ", Price: " << it->second << std::endl;
    }
}