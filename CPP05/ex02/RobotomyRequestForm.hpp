/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:58:50 by razasharuku       #+#    #+#             */
/*   Updated: 2024/03/01 11:54:36 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        const std::string   m_target;
    public:
        // コンストラクタ
        RobotomyRequestForm(std::string target);
        // コピーコンストラクタ
        RobotomyRequestForm(const RobotomyRequestForm& other);
        // コピー代入演算子
        RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
        // デストラクタ
        ~RobotomyRequestForm(void);

        // メンバ変数
        void            execute(Bureaucrat const & executor) const;
};

#endif