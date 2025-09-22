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
		std::cout << "OPE = " << ope[0] << std::endl;
		return ;
	}

	for (size_t i = 0; i < ope.size(); )
	{
		// std::cout << "TAILLE = " << ope.size() << std::endl;
		if (ope[i] == ' ')
			i++;
		if (isdigit(ope[i]) || ope[i] == '+' || ope[i] == '-' || ope[i] == '*' || ope[i] == '/')
		{
			// std::cout << "OPE1 = " << ope[i] << std::endl;
			if (isdigit(ope[i]))
			{
				stack.push(std::atoi(&ope[i]));
				std::cout << "STACK PUSH = " << stack.top() << std::endl;
			}
			// i++;
			int res = stack.top();
			stack.pop();
			if (ope[i] == '+')
			{
				std::cout << "OPE1 = " << ope[i] << std::endl;
				std::cout << "RES1 == " << res << std::endl;
				std::cout << "TOP = " << stack.top() << std::endl;
				res = res + stack.top();
				std::cout << "RES2 == " << res << std::endl;
				stack.push(res);
			}
			if (ope[i] == '-')
			{
				std::cout << "RES1 == " << res << std::endl;
				std::cout << "OPE1 = " << ope[i] << std::endl;
				std::cout << "TOP = " << stack.top() << std::endl;
				res = res - stack.top();
				// stack.pop();
				std::cout << "RES2 == " << res << std::endl;
				stack.push(res);
			}
			if (ope[i] == '*')
			{
				std::cout << "RES1 == " << res << std::endl;
				std::cout << "OPE1 = " << ope[i] << std::endl;
				std::cout << "TOP = " << stack.top() << std::endl;
				res = res * stack.top();
				// stack.pop();
				std::cout << "RES2 == " << res << std::endl;
				stack.push(res);
			}
			if (ope[i] == '/')
			{
				std::cout << "RES1 == " << res << std::endl;
				std::cout << "OPE1 = " << ope[i] << std::endl;
				std::cout << "TOP = " << stack.top() << std::endl;
				res = res / stack.top();
				// stack.pop();
				std::cout << "RES2 == " << res << std::endl;
				stack.push(res);
			}
			// std::cout << "TAILLE STACK = " << stack.size() << std::endl;
			// std::cout << "TOP STACK = " << stack.top() << std::endl;
			// std::cout << "I = " << i << std::endl;
			i++;
		}
		else
		{
			std::cout << "Error: must have operators\n";
			return ;
		}
	}
}
