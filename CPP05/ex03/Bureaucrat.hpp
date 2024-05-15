/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:07:43 by sraza             #+#    #+#             */
/*   Updated: 2024/03/01 10:12:19 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const   m_name;
        unsigned int        m_grade;
    public:
        // コンストラクタ
        Bureaucrat(void);
        Bureaucrat(std::string name, unsigned int grade);
        // コピーコンストラクタ
        Bureaucrat(const Bureaucrat& other);
        // コピー代入演算子
        Bureaucrat &operator=(const Bureaucrat& other);
        // デストラクタ
        ~Bureaucrat(void);

        // メンバ変数
        const std::string&      getName(void) const ;
        const unsigned int&     getGrade(void) const;
        void                    setGrade(unsigned int grade);
        void                    increase_grade(unsigned int grade);
        void                    decrease_grade(unsigned int grade);
        void                    signForm(AForm& form);
        void                    executeForm(AForm const & form);

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

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a);

#endif