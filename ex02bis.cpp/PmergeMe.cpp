#include "PmergeMe.hpp"
#include <cmath>

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
		// std::cout << "vector =================== " << nbr2 << std::endl;
		i++;
	}
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
			// std::cout << " ARG = " << (*it) << std::endl;
			std::cout << "Error: duplicate number\n";
			return (false);
		}
		seen.insert(*it);
	}
	return (true);
}
void	PmergeMe::fordJohn(int nbr_element)
{
	int group = vector.size() / nbr_element;
	int pair = group / 2;
	int i = 0;
	std::vector<int>::iterator first = vector.begin() + (nbr_element - 1);
	std::vector<int>::iterator second = first + nbr_element;

	while (i < pair)
	{
		// std::cout<<"size : "<< vector.size() <<"first :"<<std::distance(vector.begin(), first)<<"second :"<<std::distance(vector.begin(), second)<<std::endl;
		if (*first > *second)
		{
			swap(first, second, nbr_element);
		}

		first += nbr_element * 2;
		second += nbr_element * 2;
		i++;

	}
	if (pair > 1)
	{
		fordJohn(nbr_element * 2);
	}
	// std::cout<<"apres recusrion"<<std::endl;
	// printGroups(nbr_element);
	// std::cout << std::endl;

	i = 1;
	std::vector<int>::iterator it = vector.begin() + (nbr_element * 2); //plus petit ele 2eme pair
	// std::cout<<"nb pair : "<<pair<<" size elem : "<<nbr_element<<std::endl;
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
		// if (isSorted(nbr_element) == true)
		// 	std::cout<<"c'est trie"<<std::endl;

		// std::cout << "PRINT GRAND\n";
		// printGroups(nbr_element);
		// std::cout << "PRINT petit\n";
		// printMinGroups(nbr_element);
		if (index < 0)
		{
			// i = 0;
			// std::cout<<"???????????????????????????????????????????????????????????????"<<std::endl;
			prev = jacob;
			// std::cout<<"i == "<<i<<std::endl;
			jacob = jacobsthal(i);
			// std::cout<<"jacob : "<<jacob<<" prev : "<<prev<<std::endl;
			if (jacob - prev >= (int)min.size() / nbr_element)
				index = (min.size() / nbr_element) - 1;
			else
				index = jacob - prev - 1;
			i++;
		}
		// std::cout<<"prev"<<prev<<" jacob"<<jacob<<" index : "<<index<<"nbr element:"<<nbr_element<<"prev"<<prev<<"end calcul :"<<nbr_element * (prev) * 2 - 1<<std::endl;

		// std::cout<<"index : "<<index<<" i : "<<i<<" nb elem : "<<nbr_element<<std::endl;
		std::vector<int>::iterator it = min.begin() + (index) * nbr_element;
		std::vector<int>::iterator inserted;
		int endSize = pow(prev, 2);
		// std::cout<<"endsize == "<<endSize<<std::endl;

		if (prev == 1)
			endSize = 3;
		// std::cout<<"endsize == "<<endSize<<std::endl;
		if ((int)vector.size()/nbr_element < endSize)
		{
			// std::cout<<"if end"<<std::endl;
			endSize = (int)vector.size()/nbr_element;
		}
		// std::cout<<"endsize == "<<endSize<<std::endl;
		std::vector<int>::iterator end = vector.begin() + (endSize * nbr_element)- 1;
		inserted = binaryResearch(it + nbr_element - 1, vector.begin() + (nbr_element - 1),end, nbr_element);
		// std::cout << "INSERTED = " << *inserted << std::endl;
		// std::cout<<"petit a inserer :"<<std::distance(min.begin(), it)<<std::endl;
		// std::cout<<"emplacement dans grand a inserer :"<<std::distance(vector.begin(), inserted)<<std::endl;
		vector.insert(inserted, it, it + nbr_element);
		min.erase(it, it + nbr_element);
		index--;
	}
	// std::cout<<"fin d'une eape de recusion\n\n\n";
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
		// std::cout<<"i == "<<i<<" nbr elem : "<<nbr_ele<<std::endl;
		min.push_back(*it) ;
		it = vector.erase(it);
		i++;
		// std::cout << "PRINT petit dans erase\n";
		// for (std::vector<int>::iterator jit = min.begin(); jit != min.end(); jit++)
		// {
		// 	std::cout << *jit <<  " ";
		// }
		// std::cout<<std::endl;
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
	// std::cout<<"distance midlle = " << std::distance(vector.begin(), middle);
	// std::cout<<  "distance end :"<<std::distance(vector.begin(), end);
	// std::cout<<"distance a inserer :"<<std::distance(min.begin(), it);
	// std::cout<<"distance start  :"<<std::distance(vector.begin(), start)<<std::endl;;

	// std::cout<<"midlle = " << *middle;
	// std::cout<<  "end :"<<*end;
	// std::cout<<" a inserer :"<<*it<<std::endl;
	// std::cout<<"start  :"<<*start;

	if ((*middle) < (*it))
	{
		// std::cout << std::distance(vector.begin(), middle) << std::endl;
		if (middle == end)
			return (middle+1);
		middle += nbr_ele;
		return binaryResearch(it, middle, end, nbr_ele);
	}
	else
	{
		// std::cout <<"ELSE" <<std::distance(vector.begin(), middle) << std::endl;
		if (middle == start)
		{
			middle -= (nbr_ele-1);
			// std::cout <<"ELSE" <<std::distance(vector.begin(), (middle)) << std::endl;
			// std::cout <<"ELSE" <<*(middle) << std::endl;
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
		std::cout<<vector[i]<<" ";
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
		std::cout<<min[i]<<" ";
	}
	std::cout<<"}";
	std::cout<<std::endl;
}
