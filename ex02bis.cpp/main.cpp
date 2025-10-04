#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe instance;
	PmergeMeDeque deque;
	struct timeval	start;
	struct timeval	end;
	size_t time;

	gettimeofday(&start, NULL);

	if (ac == 1 || ac == 2)
	{
		std::cout << "Error: not enough arguments\n";
		return (0);
	}
	if (ac > 349525)
	{
		std::cout << "Error: too many numbers\n";
		return (0);
	}
	try
	{
		instance.parsing(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
		return (0);
	}
	instance.fordJohn(1);
	gettimeofday(&end, NULL);
	time = (end.tv_sec *1000000 + end.tv_usec) - (start.tv_sec *1000000 + start.tv_usec);
	std::cout << "After : ";
	instance.printVector();

	std::cout << "Time to process a range of " << instance.getVector().size() << " with std::vector<int> " << ": " << "second = " << time /1000000 << " millisecond = " << (time % 1000000) / 1000 << " microseconds = " << time % 1000 << std::endl;
	// std::cout<<instance.isSorted(1)<<std::endl;

	try
	{
		deque.parsingD(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	deque.fordJohnD(1);
	if (COMP == 1)
		std::cout<<instance.nbCmp<<std::endl;
	std::cout << "Time to process a range of " << deque.getDeque().size() << " with std::deque<int> " << ": " << "second = " << time /1000000 << " millisecond = " << (time % 1000000) / 1000 << " microseconds = " << time % 1000 << std::endl;

	// deque.printdequeD();
	// std::cout<<deque.isSortedD(1)<<std::endl;
}
