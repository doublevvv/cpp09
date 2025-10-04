#include "RPN.hpp"

/*
	PARSING :
		- minimum deux chiffres et un opérateur
		- si deux chiffres restants a la fin -> manque un operateur
		- pas de nombre supérieur à 10
		- seulement isdigit et + - *
*/

void	RPN::parsing(std::string ope)
{
	if (ope.size() < 3)
	{
		std::cout << "must have at least 3 arguments : 2 numbers and one operator\n";
		return ;
	}
	if (!isdigit(ope[0]))
	{
		std::cout << "Error: first character incorrect\n";
		return ;
	}
	for (size_t i = 0; i < ope.size(); )
	{
		if (ope[i] == ' ')
		{
			i++;
			continue ;
		}
		if (isdigit(ope[i]))
		{
			if (isdigit(ope[i + 1]))
			{
				std::cout << "Error: digit superior to 9\n";
				return ;
			}
			stack.push(std::atoi(&ope[i]));
			i++;
		}
		else if (ope[i] == '+' || ope[i] == '-' || ope[i] == '*' || ope[i] == '/')
		{
			if (stack.size() < 2)
			{
				std::cout << "Error: not enough operands for operation '" << ope[i] << "'\n";
				return ;
			}
			float first = stack.top(); stack.pop();
			float second = stack.top(); stack.pop();
			float res = 0;
			if (ope[i] == '+')
				res = second + first;
			else if (ope[i] == '-')
				res = second - first;
			else if (ope[i] == '*')
				res = second * first;
			else if (ope[i] == '/')
			{
				if (first == 0)
				{
					std::cout << "Error: division by zero\n";
					return;
				}
				res = second / first;
			}
			else
			{
				std::cout << "Error: must have operators\n";
				return ;
			}
			stack.push(res);
			i++;
		}
	}
	if (stack.size() == 1)
		std::cout << "final result = " << stack.top() << std::endl;
	else
		std::cout << "error: extra values\n";
}
