/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:35:55 by razasharuku       #+#    #+#             */
/*   Updated: 2024/03/28 13:37:33 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target), m_target(target)
{
    std::cout << "PresidentialPardonForm: Default constructor called." << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), m_target(other.m_target)
{
    std::cout << "PresidentialPardonForm: Copy constructor called." << std::endl;
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "PresidentialPardonForm: Copy assigment operator called." << std::endl;
    if (this != &other)
    {
        const_cast<std::string&>(this->m_target) = other.m_target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm: Destructor called." << std::endl;
    return ;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->get_sign() == false)
        throw AForm::UnSignedException();
    else if (executor.getGrade() > this->get_exec_Grade())
        throw AForm::GradeTooLowException();
    else 
        std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return ;
}