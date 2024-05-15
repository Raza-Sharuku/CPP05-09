/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:07:43 by sraza             #+#    #+#             */
/*   Updated: 2024/02/29 17:37:21 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include <string>
# include "AForm.hpp"

// AForm;

class Intern
{
    public:
        // コンストラクタ
        Intern(void);
        // コピーコンストラクタ
        Intern(const Intern& other);
        // コピー代入演算子
        Intern &operator=(const Intern& other);
        // デストラクタ
        ~Intern(void);

        // メンバ変数
        AForm   *makeForm(const std::string name_of_form, const std::string target_of_form);

};

#endif