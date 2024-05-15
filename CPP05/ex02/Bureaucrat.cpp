/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:24:52 by sraza             #+#    #+#             */
/*   Updated: 2024/03/28 13:19:10 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : m_name("default"), m_grade(1)
{
    std::cout << this->m_name << ": Bureaucrat: Default constructor called." << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : m_name(name), m_grade(grade)
{
    std::cout << this->m_name << ": Bureaucrat: Default constructor called." << std::endl;

    if (grade < 1)
    {
        std::cout << "This grade is out_of_range." << std::endl;
        throw (GradeTooHighException());
    }
    if (grade > 150)
    {
        std::cout << "This grade is out_of_range." << std::endl;
        throw (GradeTooLowException());
    }

    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    std::cout << this->m_name << ": Bureaucrat: Copy constructor called." << std::endl;
    *this = other;
    return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << this->m_name << ": Bureaucrat: Copy assigment operator called." << std::endl;
    if (this != &other)
    {
        const_cast<std::string&>(this->m_name) = other.m_name;
        this->m_grade = other.m_grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << this->m_name << ": Bureaucrat: Destructor called." << std::endl;
    return ;
}

// member function
const std::string& Bureaucrat::getName(void) const
{
    return (this->m_name);
}

const unsigned int& Bureaucrat::getGrade(void) const
{
    return (this->m_grade);
}

void    Bureaucrat::setGrade(unsigned int grade)
{
    if (grade > 150 || grade < 1)
        std::cout << "Can't Set this value to grade." << std::endl;
    else 
        this->m_grade = grade;
    return ;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("GradeTooHighException called");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("GradeTooLowException called");
}

// increment and decrement
void    Bureaucrat::increase_grade(unsigned int grade)
{
    this->setGrade(m_grade - grade);
    return ;
}

void    Bureaucrat::decrease_grade(unsigned int grade)
{
    this->setGrade(m_grade + grade);
    return ;
}

void    Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->getName() << " couldn't signed " << form.getName() << ". Because " << e.what() << std::endl;
        return ;
    }
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " execute " << form.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName() << ". Because " << e.what() << std::endl;
    }
}


std::ostream	&operator<<(std::ostream &o, Bureaucrat &a)
{
	o <<  a.getName() << " : Bureaucrat "  << " grade: " << a.getGrade() << std::endl;
	return (o);
}