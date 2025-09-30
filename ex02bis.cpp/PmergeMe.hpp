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
	void	fordJohn(int size);
	void	swap(std::vector<int>::iterator first, std::vector<int>::iterator second, int nbr_ele);
	void	getMin(std::vector<int>::iterator &it, int nbr_ele);
	int		jacobsthal(int index);
	std::vector<int>::iterator	binaryResearch(std::vector<int>::iterator it, std::vector<int>::iterator start, std::vector<int>::iterator end, int nbr_ele);
	void printVector();
	bool isSorted(int nb_el);
	void printGroups(int nb_elem);
	void printMinGroups(int nb_elem);

	private:
	std::vector<int> vector;
	std::vector<int> min;
	std::vector<int> max;
};

#endif
