/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raza.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:31:01 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/02 15:47:45 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <iterator>
#include <map>
#include <fstream>
#include <sstream>
#include <string>



static std::string space_remover(const std::string &str)
{
    std::string::const_iterator start = str.begin();
    std::string::const_iterator end = str.end();

    // 文字列の最初のいらないものを飛ばす
    while (start != end && (*start == ' ' || *start == '\t' || *start == '\n'))
        ++start;
    // 文字列の末尾のいらないものを飛ばす
    while (end != start && (*(end - 1) == ' ' || *(end - 1) == '\t' || *(end - 1) == '\n'))
        --end;
    
    std::string new_str = std::string(start, end);

    return (new_str);
}

int main (void)
{
    std::map<std::string, int> input_data;
    std::string         date;
    float               value;

    std::ifstream input_file("my_file.txt");

    std::string line;
    std::getline(input_file, line);
    try
    {
        if (line != "date | value")
            throw std::invalid_argument("Error : File format is Wrong");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    while (std::getline(input_file, line))
    {
        std::istringstream  iss(line);

        if (std::getline(iss, date, '|') && iss >> value)
        {
            date = space_remover(date);
            std::cout << "date : " << date << "$" << std::endl;
            std::cout << "value : " << value << "$" << std::endl;
        }
        else 
            std::cout << "Error: bad input => " << date << std::endl;
            
    }


    return (0);
}