#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
	public:
	RPN(){};
	~RPN(){};
	RPN &operator=(const RPN &rhs)
	{
		(void)rhs;
		return (*this);
	};
	RPN(const RPN &obj)
	{
		(*this) = obj;
	};
	void	parsing(std::string);

	private:
	std::stack<int> stack;

};

#endif
