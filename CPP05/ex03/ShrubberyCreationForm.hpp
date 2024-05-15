/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:07:43 by sraza             #+#    #+#             */
/*   Updated: 2024/02/27 14:54:55 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string   m_target;
    public:
        // コンストラクタ
        ShrubberyCreationForm(std::string target);
        // コピーコンストラクタ
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        // コピー代入演算子
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
        // デストラクタ
        ~ShrubberyCreationForm(void);

        // メンバ変数
        void            execute(Bureaucrat const & executor) const;
};

#endif