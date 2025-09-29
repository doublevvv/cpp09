#include "PmergeMe.hpp"

void	PmergeMe::parsing(int ac, char **arg)
{
	int i = 1;
	std::string input;
	std::string nbr;

	while (i < ac)
	{
		input = arg[i];
		for (size_t j = 0; j < input.size(); ++j)
		{
			if (!isdigit(input[j]))
			{
				std::cout << "Error: you must use only digit\n";
				return ;
			}
		}
		int nbr2 = std::atoi(input.c_str());
		if (nbr2 < 0 || nbr2 > INT_MAX)
		{
			std::cout << "Error: number incorrect\n";
			return ;
		}
		vector.push_back(nbr2);
		std::cout << "vector =================== " << nbr2 << std::endl;
		i++;
	}
	if (!checkErrors(vector))
		return ;
	createPair(vector);
}

bool	PmergeMe::checkErrors(std::vector<int> &vector)
{
	std::set<int> seen;

	for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); ++it)
	{
		if (seen.find(*it) != seen.end())
		{
			std::cout << " ARG = " << (*it) << std::endl;
			std::cout << "Error: duplicate number\n";
			return (false);
		}
		seen.insert(*it);
	}
	return (true);
}

void	PmergeMe::createPair(std::vector<int> &vector)
{
	// max.clear();
	// min.clear();
	// std::vector<int>::iterator it = vector.begin();
	std::vector<int>::iterator ite = vector.begin();
	std::vector<int>::iterator end = vector.end();
	ite++;
	end--;

	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); )
	{
		if (vector.size() % 2 != 0 && (*it) == (*end))
		{
			min.push_back(*it);
			break ;
		}
		if ((*it) > (*ite))
		{
			max.push_back((*it));
			min.push_back((*ite));
		}
		else
		{
			max.push_back((*ite));
			min.push_back((*it));
		}
		if (vector.size() % 2 == 0 && (*ite) == (*end))
			break ;
		it++;
		it++;
		ite++;
		ite++;
	}
	// std::cout << "SIZE MAX = " << max.size() << std::endl;
	for (std::vector<int>::iterator jit = max.begin(); jit != max.end(); jit++)
	{
		std::cout << "MAX = " << (*jit) << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------\n";
	for (std::vector<int>::iterator nit = min.begin(); nit != min.end(); nit++)
	{
		std::cout << "min = " << (*nit) << std::endl;
	}
	std::cout << "								SIZE MAX = " << max.size() << std::endl;
	recursiveSort(max);

	std::cout << "MAX SORTED:\n";
	std::cout << "Sorted: ";
	for (size_t k = 0; k < max.size(); ++k)
		std::cout << max[k] << " ";
	std::cout << "\n";


}

void	PmergeMe::recursiveSort(std::vector<int> &max)
{
	std::vector<int> r;
	std::vector<int> l;
	size_t i = 0;
	size_t j = max.size() - 1;
	std::cout << "SIZE MAX = " << max.size() << std::endl;
	std::cout << "I + J ===" << i + j << "I = " << i << "J === " << j << std::endl;
	int middle = (i + j) / 2;
	std::cout << "MIDDLE = " << middle << std::endl;

	for (int index = 0; index < (int)max.size(); ++index)
	{
		if (index <= middle)
			l.push_back(max[index]);
		else
			r.push_back(max[index]);
	}
	if (l.size() > 1)
		recursiveSort(l);
	if (r.size() > 1)
		recursiveSort(r);
	std::vector<int> sorted;
	size_t o = 0, p = 0;
	while (o < l.size() && p < r.size())
	{
		if (l[o] < r[p])
			sorted.push_back(l[o++]);
		else
			sorted.push_back(r[p++]);
	}
	while (o < l.size())
		sorted.push_back(l[o++]);
	while (p < r.size())
		sorted.push_back(r[p++]);

	for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
	{
		std::cout << *it << " -> SORTED ";
		std::cout << "\n";
	}
	max = sorted;
}
