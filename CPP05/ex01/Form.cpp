/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:33:29 by razasharuku       #+#    #+#             */
/*   Updated: 2024/03/28 11:00:57 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, unsigned int sign_grade, unsigned int exec_grade) 
: m_name(name), m_sign_grade(sign_grade), m_exec_grade(exec_grade), m_singed(false)
{
    std::cout << this->m_name << ": Form: Default constructor called." << std::endl;
    if (m_sign_grade < 1 || m_exec_grade < 1)
    {
        std::cout << "This grade is out_of_range." << std::endl;
        throw (GradeTooHighException());
    }
    if (m_sign_grade > 150 || m_exec_grade > 150)
    {
        std::cout << "This grade is out_of_range." << std::endl;
        throw (GradeTooLowException());
    }
    return ;
}

Form::Form(const Form& other)
: m_name(other.m_name), m_sign_grade(other.m_sign_grade), m_exec_grade(other.m_exec_grade), m_singed(other.m_singed)
{
    std::cout << this->m_name << ": Form: Copy constructor called." << std::endl;
    return ;
}

Form &Form::operator=(const Form& other)
{
    std::cout << this->m_name << ": Form: Copy assigment operator called." << std::endl;
    if (this != &other)
    {
        const_cast<std::string&>(this->m_name) = other.m_name;
        const_cast<unsigned int&>(this->m_sign_grade) = other.m_sign_grade;
        const_cast<unsigned int&>(this->m_exec_grade) = other.m_exec_grade;
        this->m_singed = other.m_singed;
    }
    return (*this);
}

Form::~Form(void)
{
    std::cout << this->m_name << ": Form: Destructor called." << std::endl;
    return ;
}

const std::string Form::getName(void) const
{
    return (this->m_name);
}

bool Form::get_sign(void) const
{
    return (this->m_singed);
}

void Form::reset_sign(void)
{
    this->m_singed = false;
}

const unsigned int& Form::get_sign_Grade(void) const
{
    return (this->m_sign_grade);
}

const unsigned int& Form::get_exec_Grade(void) const
{
    return (this->m_exec_grade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->get_sign_Grade())
        throw Form::GradeTooLowException();
    else
        this->m_singed = true;
}


const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Form: GradeTooHighException called");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Form: GradeTooLowException called");
}

std::ostream	&operator<<(std::ostream &o, Form &a)
{
    o << "---------------- " << a.getName() << " ---------------" << "\n"\
    << "Is Signed ? :" << (a.get_sign() ? "Yes" : "No") << "\n"\
    << "Sign_Grade :" << a.get_sign_Grade() << "\n"\
    << "Execute_Grade :" << a.get_exec_Grade() << std::endl;
	return (o);
}