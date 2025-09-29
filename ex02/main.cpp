#include "PmergeMe.hpp"

// * list and vector

int	main(int ac, char **av)
{
	PmergeMe instance;

	if (ac == 1 || ac == 2)
	{
		std::cout << "Error: not enough arguments\n";
		return (0);
	}
	instance.parsing(ac, av);
}
