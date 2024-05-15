/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:16:26 by razasharuku       #+#    #+#             */
/*   Updated: 2024/02/27 19:17:09 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string   m_target;
    public:
        // コンストラクタ
        PresidentialPardonForm(std::string target);
        // コピーコンストラクタ
        PresidentialPardonForm(const PresidentialPardonForm& other);
        // コピー代入演算子
        PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
        // デストラクタ
        ~PresidentialPardonForm(void);

        // メンバ変数
        void            execute(Bureaucrat const & executor) const;
};

#endif