/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:05:36 by razasharuku       #+#    #+#             */
/*   Updated: 2024/06/02 10:32:29 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "\033[32m" << "++++++++++++++++++ test start 1 ++++++++++++++++\n" << "\033[0m" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(111111);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
   
	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 1 +++++++++++++++" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "++++++++++++++++++ test start 2 ++++++++++++++++" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "const check\n" << "\033[0m" << std::endl;

	MutantStack<int> stack1;

	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);
	stack1.push(5);
	
	const MutantStack<int> stack3 = stack1;
	MutantStack<int>::const_iterator it_stack = stack3.begin();
	MutantStack<int>::const_iterator ite_stack = stack3.end();
	++it_stack;
	--it_stack;
	while (it_stack != ite_stack)
	{
		std::cout << *it_stack << std::endl;
		++it_stack;
	}

	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 2 +++++++++++++++\n" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "++++++++++++++++++ test start 3 ++++++++++++++++" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "List check\n" << "\033[0m" << std::endl;

	std::cout << "--------- MutantStack -----------" << std::endl;

	MutantStack<int> stack2;

	stack2.push(1);
	stack2.push(2);
	stack2.push(3);
	stack2.push(4);
	stack2.push(5);

	MutantStack<int>::iterator it_stack2 = stack2.begin();
	MutantStack<int>::iterator ite_stack2 = stack2.end();
	++it_stack2;
	--it_stack2;
	while (it_stack2 != ite_stack2)
	{
		std::cout << *it_stack2 << std::endl;
		++it_stack2;
	}

	std::cout << "--------- list -----------" << std::endl;
	
	std::list<int> stack_list;
	stack_list.push_back(1);
	stack_list.push_back(2);
	stack_list.push_back(3);
	stack_list.push_back(4);
	stack_list.push_back(5);

	std::list<int>::iterator it_list = stack_list.begin();
	std::list<int>::iterator ite_list = stack_list.end();
	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}



	std::cout << "\033[32m" << "\n++++++++++++++++++ test finish 3 +++++++++++++++\n" << "\033[0m" << std::endl;

    return 0;
}

// __attribute__((destructor))
// static void destructor() 
// {
//     system("leaks -q ex");
// }