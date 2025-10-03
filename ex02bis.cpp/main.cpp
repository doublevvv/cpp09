#include "PmergeMe.hpp"

// * list and vector

int	main(int ac, char **av)
{
	PmergeMe instance;
	PmergeMeDeque deque;

	if (ac == 1 || ac == 2)
	{
		std::cout << "Error: not enough arguments\n";
		return (0);
	}
	instance.parsing(ac, av);
	instance.fordJohn(1);
	std::cout << "After : ";
	instance.printVector();
	// std::cout << "Time to process a range of " <<
	// std::cout<<instance.isSorted(1)<<std::endl;

	deque.parsingD(ac, av);
	deque.fordJohnD(1);
	if (COMP == 1)
		std::cout<<instance.nbCmp<<std::endl;
	// deque.printdequeD();
	// std::cout<<deque.isSortedD(1)<<std::endl;
}
