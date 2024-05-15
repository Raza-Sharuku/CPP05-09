/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:07:43 by sraza             #+#    #+#             */
/*   Updated: 2024/03/28 10:50:59 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   m_name;
        const unsigned int  m_sign_grade;
        const unsigned int  m_exec_grade;
        bool                m_singed;
    public:
        // コンストラクタ
        Form(std::string name, unsigned int sign_grade, unsigned int exec_grade);
        // コピーコンストラクタ
        Form(const Form& other);
        // コピー代入演算子
        Form &operator=(const Form& other);
        // デストラクタ
        ~Form(void);

        // メンバ変数
        const std::string       getName(void) const;
        bool                    get_sign(void) const;
        void                    reset_sign(void);
        const unsigned int&     get_sign_Grade(void) const;
        const unsigned int&     get_exec_Grade(void) const;
        void                    beSigned(const Bureaucrat& bureaucrat);

        // nested class
        class   GradeTooHighException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
        class   GradeTooLowException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
        
};

std::ostream	&operator<<(std::ostream &o, Form &a);

#endif