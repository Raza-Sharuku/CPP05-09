/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:16:23 by razasharuku       #+#    #+#             */
/*   Updated: 2024/03/28 13:56:34 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    std::cout << "Intern: Default constructor called." << std::endl;
    return ;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern: Bureaucrat: Copy constructor called." << std::endl;
    *this = other;
    return ;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern: Bureaucrat: Copy assigment operator called." << std::endl;
    if (this != &other)
        return (*this);
    return (*this);
}

Intern::~Intern(void)
{
    std::cout << "Intern: Destructor called." << std::endl;
    return ;
}

AForm   *Intern::makeForm(const std::string name_of_form, const std::string target_of_form)
{
    std::string form_names[] = {"ShrubberyCreationForm","RobotomyRequestForm", "PresidentialPardonForm"};
    int i = 0;
    while (i < 3 && name_of_form != form_names[i])
        i++;
	switch (i)
	{
	case 0:
    {
		std::cout << "Intern creates " << name_of_form << std::endl;
		return (new ShrubberyCreationForm(target_of_form));
    }
	case 1:
    {
		std::cout << "Intern creates " << name_of_form << std::endl;
		return (new RobotomyRequestForm(target_of_form));
    }
	case 2:
    {
		std::cout << "Intern creates " << name_of_form << std::endl;
		return (new PresidentialPardonForm(target_of_form));
    }
	default:
		std::cout << "Intern couldn't create Form.\n" << std::endl;
		return (NULL);
	}
}