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
				std::cerr << "Error: you must use only digit\n";
				return ;
			}
		}
		int nbr2 = std::atoi(input.c_str());
		if (nbr2 < 0 || nbr2 > INT_MAX)
		{
			std::cerr << "Error: number incorrect\n";
			return ;
		}
		vector.push_back(nbr2);
		i++;
	}
	// std::cout << "Before : ";
	// printVector();
	if (!checkErrors(vector))
		return ;
}

bool	PmergeMe::checkErrors(std::vector<int> &vector)
{
	std::set<int> seen;

	for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); ++it)
	{
		if (seen.find(*it) != seen.end())
		{
			std::cout << "Error: duplicate number\n";
			return (false);
		}
		seen.insert(*it);
	}
	return (true);
}

void	PmergeMe::printCompPair(std::vector<int>::iterator first, std::vector<int>::iterator second)
{
	std::cout<<"comparing :"<<*first<<" and :"<<*second<<std::endl;
}

void	PmergeMe::fordJohn(int nbr_element)
{
	// nbrelement = dans le groupe
	// pair de 2 groupes
	int group = vector.size() / nbr_element;
	int pair = group / 2;
	int i = 0;
	std::vector<int>::iterator first = vector.begin() + (nbr_element - 1);
	std::vector<int>::iterator second = first + nbr_element;
	if (LOG == 1)
	{
		std::cout<<"list before first step for size group: "<<nbr_element<<std::endl;
		printGroups(nbr_element);
	}
	while (i < pair)
	{
		nbCmp++;
		if (LOG == 1)
			printCompPair(first, second);
		if (*first > *second)
		{
			swap(first, second, nbr_element);
		}

		first += nbr_element * 2;
		second += nbr_element * 2;
		i++;
	}
	if (LOG == 1)
	{
		std::cout<<"list after first step for size group: "<<nbr_element<<std::endl;
		printGroups(nbr_element);
	}
	if (pair > 1)
	{
		if (LOG == 1)
			std::cout<<"\n\trecursively call fordjohn\n"<<std::endl;
		fordJohn(nbr_element * 2);
	}
	i = 1;
	std::vector<int>::iterator it = vector.begin() + (nbr_element * 2); //plus petit ele 2eme pair
	while (i < pair)
	{
		getMin(it, nbr_element);
		it += nbr_element;
		i++;
	}
	if (group % 2 == 1)
	{
		it = vector.begin() + (nbr_element * (vector.size()/nbr_element - 1));
		getMin(it, nbr_element);
	}
	i = 0;
	int jacob = 1;
	int prev = 1;
	int index = -1;
	while (min.size() > 0)
	{
		if (index < 0)
		{
			prev = jacob;
			jacob = jacobsthal(i);
			// std::cout << "Ford Johnson\n";
			if (jacob - prev >= (int)min.size() / nbr_element)
				index = (min.size() / nbr_element) - 1;
			else
				index = jacob - prev - 1;
			i++;
		}
		std::vector<int>::iterator it = min.begin() + (index) * nbr_element;
		std::vector<int>::iterator inserted;
		int endSize = prev + jacob - 1;
		if (prev == 1)
			endSize = 3;
		if ((int)vector.size()/nbr_element < endSize)
		{
			endSize = (int)vector.size()/nbr_element;
		}
		std::vector<int>::iterator end = vector.begin() + (endSize * nbr_element)- 1;
		if (LOG == 1)
		{
			std::cout<<"sorted list before binary search: "<<std::endl;
			printGroups(nbr_element);
			std::cout<<std::endl;
			std::cout<<"unsorted list before binary search: "<<std::endl;
			printMinGroups(nbr_element);
		}
		inserted = binaryResearch(it + nbr_element - 1, vector.begin() + (nbr_element - 1),end, nbr_element);
		vector.insert(inserted, it, it + nbr_element);
		min.erase(it, it + nbr_element);
		if (LOG == 1)
		{
			std::cout<<"sorted list after binary search: "<<std::endl;
			printGroups(nbr_element);
			std::cout<<std::endl;
			std::cout<<"unsorted list after binary search: "<<std::endl;
			printMinGroups(nbr_element);
		}
		index--;
	}
	if (LOG == 1)
		std::cout<<"\n\tend pmergme call\n\n\n";
}

void	PmergeMe::swap(std::vector<int>::iterator first, std::vector<int>::iterator second, int nbr_ele)
{
	int i = 0;

	while (i < nbr_ele)
	{
		std::swap(*(first - i), *(second - i));
		i++;
	}
}

void	PmergeMe::getMin(std::vector<int>::iterator &it, int nbr_ele)
{
	int i = 0;
	while (i < nbr_ele)
	{
		min.push_back(*it) ;
		it = vector.erase(it);
		i++;
	}
}

int	PmergeMe::jacobsthal(int index)
{
	int suite[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	return (suite[index]);
}
std::vector<int>::iterator	PmergeMe::binaryResearch(std::vector<int>::iterator it, std::vector<int>::iterator start, std::vector<int>::iterator end, int nbr_ele)
{
	int index = ((std::distance(start, end) / nbr_ele) / 2) * nbr_ele;
	std::vector<int>::iterator middle = start + index;
	nbCmp++;
	if (LOG == 1)
		std::cout<<"binary search insert :"<<*it<<" comparing with :"<<*middle<<std::endl;
	if ((*middle) < (*it))
	{
		if (middle == end)
			return (middle+1);
		middle += nbr_ele;
		return binaryResearch(it, middle, end, nbr_ele);
	}
	else
	{
		if (middle == start)
		{
			middle -= (nbr_ele-1);
			return (middle);
		}
		middle -= nbr_ele;
		return binaryResearch(it, start, middle, nbr_ele);
	}
	return (it);

}

void PmergeMe::printVector()
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout<<vector[i]<<" ";
	}
	std::cout<<std::endl;
}

bool PmergeMe::isSorted(int nb_el)
{
	int prev = vector[nb_el-1];
	for (size_t i = nb_el + nb_el-1; i <vector.size();i+=nb_el)
	{
		if (vector[i] < prev)
			return false;
		prev = vector[i];
	}
	return true;
}

void PmergeMe::printGroups(int nb_elem)
{
	std::cout<<"{";
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (i > 0 && i%nb_elem == 0)
			std::cout<<"} {";
		else if (i % nb_elem + 1 != 0 && i != 0)
		{
			std::cout<<" ";
		}
		std::cout<<vector[i];
	}
	std::cout<<"}";
	std::cout<<std::endl;
}


void PmergeMe::printMinGroups(int nb_elem)
{
	std::cout<<"{";
	for (size_t i = 0; i < min.size(); i++)
	{
		if (i > 0 && i%nb_elem == 0)
			std::cout<<"} {";
		else if (i % nb_elem + 1 != 0 && i != 0)
		{
			std::cout<<" ";
		}
		std::cout<<min[i];
	}
	std::cout<<"}";
	std::cout<<std::endl;
}
