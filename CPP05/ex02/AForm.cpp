/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:33:29 by razasharuku       #+#    #+#             */
/*   Updated: 2024/02/27 14:19:54 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, unsigned int sign_grade, unsigned int exec_grade, std::string target) 
: m_name(name), m_sign_grade(sign_grade), m_exec_grade(exec_grade), m_singed(false), m_target(target)
{
    std::cout << this->m_name << ": AForm: Default constructor called." << std::endl;
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

AForm::AForm(const AForm& other)
: m_name(other.m_name), m_sign_grade(other.m_sign_grade), m_exec_grade(other.m_exec_grade), m_singed(other.m_singed), m_target(other.m_target)
{
    std::cout << this->m_name << ": AForm: Copy constructor called." << std::endl;
    return ;
}

AForm &AForm::operator=(const AForm& other)
{
    std::cout << this->m_name << ": AForm: Copy assigment operator called." << std::endl;
    if (this != &other)
    {
        const_cast<std::string&>(this->m_name) = other.m_name;
        const_cast<std::string&>(this->m_target) = other.m_target;
        const_cast<unsigned int&>(this->m_sign_grade) = other.m_sign_grade;
        const_cast<unsigned int&>(this->m_exec_grade) = other.m_exec_grade;
        this->m_singed = other.m_singed;
    }
    return (*this);
}

AForm::~AForm(void)
{
    std::cout << this->m_name << ": AForm: Destructor called." << std::endl;
    return ;
}

const std::string AForm::getName(void) const
{
    return (this->m_name);
}

const std::string AForm::get_target(void) const
{
    return (this->m_target);
}

bool AForm::get_sign(void) const
{
    return (this->m_singed);
}

void AForm::reset_sign(void)
{
    this->m_singed = false;
}

const unsigned int& AForm::get_sign_Grade(void) const
{
    return (this->m_sign_grade);
}

const unsigned int& AForm::get_exec_Grade(void) const
{
    return (this->m_exec_grade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->get_sign_Grade())
        throw AForm::GradeTooLowException();
    else
        this->m_singed = true;
}


const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("AForm: GradeTooHighException called");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("AForm: GradeTooLowException called");
}

const char *AForm::UnSignedException::what(void) const throw()
{
    return ("AForm: UnSignedException called");
}

std::ostream	&operator<<(std::ostream &o, AForm &a)
{
    o << "---------------- " << a.getName() << " ---------------" << "\n"\
    << "Is Signed ? :" << (a.get_sign() ? "Yes" : "No") << "\n"\
    << "Sign_Grade :" << a.get_sign_Grade() << "\n"\
    << "Execute_Grade :" << a.get_exec_Grade() << std::endl;
	return (o);
}