/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:07:43 by sraza             #+#    #+#             */
/*   Updated: 2024/03/28 11:59:44 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _A_FORM_HPP
# define _A_FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"


class Bureaucrat;

class AForm
{
    private:
        const std::string   m_name;
        const unsigned int  m_sign_grade;
        const unsigned int  m_exec_grade;
        bool                m_singed;
        const std::string   m_target;
    public:
        // コンストラクタ
        AForm(std::string name, unsigned int sign_grade, unsigned int exec_grade, std::string target);
        // コピーコンストラクタ
        AForm(const AForm& other);
        // コピー代入演算子
        AForm &operator=(const AForm& other);
        // デストラクタ
        virtual ~AForm(void);

        // メンバ変数
        const std::string       getName(void) const;
        bool                    get_sign(void) const;
        void                    reset_sign(void);
        const unsigned int&     get_sign_Grade(void) const;
        const unsigned int&     get_exec_Grade(void) const;
        const std::string       get_target(void) const;
        void                    beSigned(const Bureaucrat& bureaucrat);

        // 純粋仮想関数（抽象クラスにするために）
        virtual void            execute(Bureaucrat const & executor) const = 0;

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
        class   UnSignedException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &o, AForm &a);

#endif