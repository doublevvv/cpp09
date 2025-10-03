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
#include <deque>

#define COMP 1
#define LOG 1

class PmergeMe
{
	public:
	int nbCmp;
	PmergeMe(){nbCmp = 0;};
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
	void	printCompPair(std::vector<int>::iterator first, std::vector<int>::iterator second);

	private:
	std::vector<int> vector;
	std::vector<int> min;
	std::vector<int> max;
};

class PmergeMeDeque
{
	public:
	PmergeMeDeque(){};
	~PmergeMeDeque(){};
	PmergeMeDeque &operator=(const PmergeMeDeque &rhs)
	{
		(void)rhs;
		return (*this);
	};
	PmergeMeDeque(const PmergeMeDeque &obj)
	{
		(*this) = obj;
	};
	void	parsingD(int ac, char **arg);
	bool	checkErrorsD(std::deque<int> &list);
	void	fordJohnD(int size);
	void	swapD(std::deque<int>::iterator first, std::deque<int>::iterator second, int nbr_ele);
	void	getMinD(std::deque<int>::iterator &it, int nbr_ele);
	int		jacobsthalD(int index);
	std::deque<int>::iterator	binaryResearchD(std::deque<int>::iterator it, std::deque<int>::iterator start, std::deque<int>::iterator end, int nbr_ele);
	void printdequeD();
	bool isSortedD(int nb_el);
	void printGroupsD(int nb_elem);
	void printMinGroupsD(int nb_elem);

	private:
	std::deque<int> deque;
	std::deque<int> min;
	std::deque<int> max;
};
#endif
