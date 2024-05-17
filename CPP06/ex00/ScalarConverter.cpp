/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:06 by razasharuku       #+#    #+#             */
/*   Updated: 2024/05/17 11:09:39 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}


ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

// ------------------------------------------------------ //

enum char_type
{
    INVALID = -1,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
};

static bool is_char(const std::string &str)
{
    if (str.length() != 1)
        return (false);
    if (isdigit(str.at(0)) ||  str.at(0) < -127 || str.at(0) > 127)
        return (false);
    return (true);
}

static bool is_int(const std::string &str)
{
    int i = 0;
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

static bool is_float(const std::string &str)
{
    unsigned long i = 0;
    bool find_dot = false;

    if (str[str.length() - 1] != 'f')
        return (false);
    if (str[i] == '-')
        i++;
    while (i <= str.length() - 2)
    {
        if (str[i] == '.' && find_dot == true)
            return (false);
        else if (str[i] == '.')
        {
            find_dot = true;
            i++;
            continue;
        }
        else if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

static bool is_double(const std::string &str)
{
    unsigned long i = 0;
    bool find_dot = false;

    if (str[i] == '-')
        i++;
    while (i < (str.length()))
    {
        if (str[i] == '.' && find_dot == true)
            return (false);
        else if (str[i] == '.')
        {
            find_dot = true;
            i++;
            continue;
        }
        else if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

static char_type getType(const std::string &str)
{
    if (is_char(str))
        return (CHAR);
    else if (is_int(str))
        return (INT);
    else if (is_double(str))
        return (DOUBLE);
    else if (is_float(str))
        return (FLOAT);
    return (INVALID);
}

static void print_char_ver(std::string str)
{
    std::cout << "char: " << (str).c_str() << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f"  << std::endl;
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
    return ;
}

static void print_int_ver(std::string str)
{
    int num = atoi(str.c_str());
    long double ld_num = strtold(str.c_str(), NULL);

    // char型
    if (num < 0 || num >= 128)
        std::cout << "char: impossible" << std::endl;
    else if (num < 32 || num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(num) << std::endl;
	// INT型
    if ( ld_num < static_cast<long double> (INT_MIN) || ld_num > static_cast<long double> (INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	// FLOAT型
    if (ld_num == 0)
        std::cout << "double: 0.0f" << std::endl;
    else if (ld_num < -std::numeric_limits<float>::max() || ld_num > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
    {
        std::cout << "float: ";
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
    }
    // DOUBLE型
    if (ld_num == 0)
        std::cout << "double: 0.0" << std::endl;
    else if (ld_num < -std::numeric_limits<double>::max() || ld_num > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
    {
        std::cout << "double: ";
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(ld_num) << std::endl;
    }
    return ;
}

static void print_float_ver(std::string str)
{
    float f_num = atof(str.c_str());
    long double ld_num = strtold(str.c_str(), NULL);

    // CHAR型
    if (f_num < 0 || f_num >= 128)
        std::cout << "char: impossible" << std::endl;
    else if (f_num < 32 || f_num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(f_num) << std::endl;
    // INT型
	if ( ld_num < static_cast<double> (INT_MIN) || ld_num > static_cast<double> (INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f_num) << std::endl;
	// FLOAT型
    if (ld_num == 0)
        std::cout << "double: 0.0f" << std::endl;
    else if (ld_num < -std::numeric_limits<float>::max() || ld_num > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
    {
        std::cout << "float: ";
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(f_num) << "f" << std::endl;
    }
    // DOUBLE型
    if (ld_num == 0)
        std::cout << "double: 0.0" << std::endl;
    else if (ld_num < -std::numeric_limits<double>::max() || ld_num > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
    {
        std::cout << "double: ";
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(ld_num) << std::endl;
    }
    return ;
}

static void print_double_ver(std::string str)
{
    double d_num = strtod(str.c_str(), NULL);
    long double ld_num = strtold(str.c_str(), NULL);

    // CHAR型
    if (d_num < 0 || d_num >= 128)
        std::cout << "char: impossible" << std::endl;
    else if (d_num < 32 || d_num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(d_num) << std::endl;
    // INT型
	if ( ld_num < static_cast<double> (INT_MIN) || ld_num > static_cast<double> (INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d_num) << std::endl;
	// FLOAT型
    if (ld_num == 0)
        std::cout << "double: 0.0f" << std::endl;
    else if (ld_num < -std::numeric_limits<float>::max() || ld_num > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
    {
        std::cout << "float: ";
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d_num) << "f" << std::endl;
    }
    // DOUBLE型
    if (ld_num == 0)
        std::cout << "double: 0.0" << std::endl;
    else if (ld_num < -std::numeric_limits<double>::max() || ld_num > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
    {
        std::cout << "double: ";
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(ld_num) << std::endl;
    }
    return ;
}

static void print_infinity(std::string str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nan" || str == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if(str == "-inff" || str == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (str == "+inf" || str == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    return ;
}

void ScalarConverter::convert(std::string str)
{
    char_type type;

    if (str == "-inff" || str == "+inff" || str == "nanf" 
        || str == "-inf" || str == "+inf"  || str == "nan")
        return (print_infinity(str));
    
    type = getType(str);
    std::cout <<  "\033[33m" << "\nThe type of this input is : " << type << " (INVALID = -1, CHAR = 1, INT = 2, FLOAT = 3, DOUBLE = 4)\n" << "\033[0m" << std::endl;

    switch (type)
    {
    case CHAR:
        print_char_ver(str);
        break;
    case INT:
        print_int_ver(str);
        break;
    case FLOAT:
        print_float_ver(str);
        break;
    case DOUBLE:
        print_double_ver(str);
        break;
    case INVALID:
        std::cout << "the type conversion is impossible" << std::endl;
        break;
    default:
        std::cout << "the type conversion is impossible" << std::endl;
        break;
    }
}