#include "RPN.hpp"

int	main(int ac, char **av)
{
	RPN instance;
	if (ac != 2)
	{
		std::cout << "must have one argument\n";
		return (0);
	}
	instance.parsing(av[1]);

}
