/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:28:19 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/26 09:54:12 by razasharuku      ###   ########.fr       */
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
        this->database = other.database;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

// --------------------------------------------------------------------------------------------------------------------------------- //
// ------------------------------                             ここから下が主な処理                       ------------------------------ //
// --------------------------------------------------------------------------------------------------------------------------------- //


static std::string space_remover(const std::string &str)
{
    const char* start = str.c_str();
    const char* end = start + str.length();

    // 文字列の最初のいらないものを飛ばす
    while (start != end && (*start == ' ' || *start == '\t' || *start == '\n'))
        ++start;
    // 文字列の末尾のいらないものを飛ばす
    while (end != start && (*(end - 1) == ' ' || *(end - 1) == '\t' || *(end - 1) == '\n'))
        --end;
    
    std::string new_str(start, end - start);
    return (new_str);
}

static bool is_valid_day(const std::string &date)
{
    if (date[8] > '3')
        return (false);
    if (date[8] == '3' && date[9] > '1')
        return (false);
    
    return (true);
}

static bool is_valid_month(const std::string &date)
{
    if (date[5] > '1')
        return (false);
    if (date[5] == '1' && date[6] > '2')
        return (false);
    
    return (true);
}

static bool is_valid_date(const std::string &date) 
{    
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (false);
    for (size_t i = 0; i < date.length();i++)
    {
        if (i != 4 && i != 7 && isdigit(date[i]) == 0)
            return (false);
    }
    if (!is_valid_month(date) || !is_valid_day(date))
        return (false);

    return (true);
}

static float return_certain_value(const std::map<std::string, float> &dates, const std::string &searchdate)
{
    std::map<std::string, float>::const_iterator it;
    for (it = dates.begin(); it != dates.end(); ++it)
    {
        if (it->first > searchdate)
        {
            if (it != dates.begin())
            {
                --it;
                return (it->second);
            }
            break;
        }
    }
    
    throw std::runtime_error("Error : couldn't found valid date.");
} 

void BitcoinExchange::collect_data_csv(const std::string &data_csv)
{
    std::string         date;
    float               exchangerate;

    std::ifstream file;
    file.open(data_csv);
    if (!file)
        throw  std::runtime_error("Error : File couldn't open. ");
    
    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate")
        throw  std::runtime_error("Error : File format is Wrong");

    while (std::getline(file, line))
    {
        line = space_remover(line);
        std::istringstream  iss(line);

        if (std::getline(iss, date, ',') && iss >> exchangerate)
            (this->database)[date] = exchangerate;
    }
    file.close();
    return ;
}

void    BitcoinExchange::calculate_value(const std::string &input)
{
    std::map<std::string, int>  input_data;
    std::string                 date;
    float                       value;
    float                       exchangerate;
    std::string                 line;
    std::ifstream               input_file;

    input_file.open(input);
    if (!input_file)
        throw  std::runtime_error("Error : File couldn't open. ");

    std::getline(input_file, line);
    if (line != "date | value")
        throw std::runtime_error("Error : File format is Wrong");

    while (std::getline(input_file, line))
    {
        std::istringstream  iss(line);
        try
        {
            if (std::getline(iss, date, '|') && iss >> value)
            {
                if (value < 0)
                    throw std::runtime_error("Error: not a positive number.");
                if (value > 1000)
                    throw std::runtime_error("Error: too large a number.");
                date = space_remover(date);
                if (!is_valid_date(date))
                    throw std::runtime_error("Error: invalid date format. (usage: yyyy-mm-dd)");
                
                exchangerate = return_certain_value(this->database, date);
                std::cout << date << " => " << value << " = " << value * exchangerate << std::endl;
            }
            else 
                std::cout << "Error: bad input => " << date << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return ;
}
