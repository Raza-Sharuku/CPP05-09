/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:25:29 by sraza             #+#    #+#             */
/*   Updated: 2024/03/28 13:46:10 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "\033[1;33m" << "++++++++++++++++++ START ++++++++++++++++++++\n" << "\033[0m" << std::endl;
	try
    {
        // それぞれ使うBureaucratのサイングレードとかを変化させてエラーをCatchさせる

        std::cout << "\033[1;35m" << "+++++++++++++ TEST 1 _START ++++++++++\n" << "\033[0m" << std::endl;

        Bureaucrat              raza("raza",1);
        ShrubberyCreationForm   form("creating_form");

        std::cout << "\n" << raza;
        std::cout << "\n" << form;

        raza.signForm(form);
        raza.executeForm(form);

        std::cout << "\033[1;35m" << "+++++++++++++ TEST 1 _END ++++++++++\n" << "\033[0m" << std::endl;





        std::cout << "\033[1;36m" << "+++++++++++++ TEST 2 _START ++++++++++\n" << "\033[0m" << std::endl;

        Bureaucrat              Harry("Harry",40);
        RobotomyRequestForm     form1("robotomize_form");

        std::cout << Harry;
        std::cout << "\n" << form1;

        Harry.signForm(form1);
        Harry.executeForm(form1);
        Harry.executeForm(form1);
        Harry.executeForm(form1);
        Harry.executeForm(form1);

        std::cout << "\n \033[1;36m" << "+++++++++++++ TEST 2 _END ++++++++++\n" << "\033[0m" << std::endl;




        std::cout << "\033[1;34m" << "+++++++++++++ TEST 3 _START ++++++++++\n" << "\033[0m" << std::endl;

        Bureaucrat              Sirius("Sirius Black",5);
        PresidentialPardonForm  form2("pardon");

        std::cout << Sirius;
        std::cout << "\n" << form2;

        Sirius.signForm(form2);
        Sirius.executeForm(form2);

        std::cout << "\n \033[1;34m" << "+++++++++++++ TEST 3 _END ++++++++++\n" << "\033[0m" << std::endl;

	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\033[1;33m" << "++++++++++++++++++ END ++++++++++++++++++++\n" << "\033[0m" << std::endl;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q ex");
}