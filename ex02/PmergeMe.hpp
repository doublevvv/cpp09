#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
#include <cstdlib>
#include <sstream>
#include <set>

class PmergeMe
{
	public:
	PmergeMe(){};
	~PmergeMe(){};
	PmergeMe &operator=(const PmergeMe &rhs)
	{
		(void)rhs;
		return (*this);
	};
	PmergeMe(const PmergeMe &obj)
	{
		(*this) = obj;
	};
	void	parsing(int ac, char **arg);
	bool	checkErrors(std::vector<int> &list);
	void	createPair(std::vector<int> &list);
	void	recursiveSort(std::vector<int> &max);

	private:
	std::vector<int> vector;
	// std::list<int> list;
	std::vector<int> min;
	std::vector<int> max;
};

#endif
