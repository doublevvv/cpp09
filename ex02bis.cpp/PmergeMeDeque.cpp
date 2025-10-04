#include "PmergeMe.hpp"
#include <cmath>

const char *PmergeMeDeque::Error::what() const throw()
{
	return ("Error: arguments not valid");
}

const char *PmergeMeDeque::noDigit::what() const throw()
{
	return ("Error: you must use only digit");
}

const char *PmergeMeDeque::incorrectNbr::what() const throw()
{
	return ("Error: number incorrect");
}

void	PmergeMeDeque::parsingD(int ac, char **arg)
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
		deque.push_back(nbr2);
		i++;
	}
	if (!checkErrorsD(deque))
		throw Error();
}

bool	PmergeMeDeque::checkErrorsD(std::deque<int> &deque)
{
	std::set<int> seen;

	for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); ++it)
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
void	PmergeMeDeque::fordJohnD(int nbr_element)
{
	int group = deque.size() / nbr_element;
	int pair = group / 2;
	int i = 0;
	std::deque<int>::iterator first = deque.begin() + (nbr_element - 1);
	std::deque<int>::iterator second = first + nbr_element;

	while (i < pair)
	{
		// std::cout<<"size : "<< deque.size() <<"first :"<<std::distance(deque.begin(), first)<<"second :"<<std::distance(deque.begin(), second)<<std::endl;
		if (*first > *second)
		{
			swapD(first, second, nbr_element);
		}

		first += nbr_element * 2;
		second += nbr_element * 2;
		i++;

	}
	if (pair > 1)
	{
		fordJohnD(nbr_element * 2);
	}
	// std::cout<<"apres recusrion"<<std::endl;
	// printGroups(nbr_element);
	// std::cout << std::endl;

	i = 1;
	std::deque<int>::iterator it = deque.begin() + (nbr_element * 2); //plus petit ele 2eme pair
	// std::cout<<"nb pair : "<<pair<<" size elem : "<<nbr_element<<std::endl;
	while (i < pair)
	{
		getMinD(it, nbr_element);
		it += nbr_element;
		i++;
	}
	if (group % 2 == 1)
	{
		it = deque.begin() + (nbr_element * (deque.size()/nbr_element - 1));
		getMinD(it, nbr_element);
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
			jacob = jacobsthalD(i);
			// std::cout<<"jacob : "<<jacob<<" prev : "<<prev<<std::endl;
			if (jacob - prev >= (int)min.size() / nbr_element)
				index = (min.size() / nbr_element) - 1;
			else
				index = jacob - prev - 1;
			i++;
		}
		// std::cout<<"prev"<<prev<<" jacob"<<jacob<<" index : "<<index<<"nbr element:"<<nbr_element<<"prev"<<prev<<"end calcul :"<<nbr_element * (prev) * 2 - 1<<std::endl;

		// std::cout<<"index : "<<index<<" i : "<<i<<" nb elem : "<<nbr_element<<std::endl;
		std::deque<int>::iterator it = min.begin() + (index) * nbr_element;
		std::deque<int>::iterator inserted;
		int endSize = pow(prev, 2);
		// std::cout<<"endsize == "<<endSize<<std::endl;

		if (prev == 1)
			endSize = 3;
		// std::cout<<"endsize == "<<endSize<<std::endl;
		if ((int)deque.size()/nbr_element < endSize)
		{
			// std::cout<<"if end"<<std::endl;
			endSize = (int)deque.size()/nbr_element;
		}
		// std::cout<<"endsize == "<<endSize<<std::endl;
		std::deque<int>::iterator end = deque.begin() + (endSize * nbr_element)- 1;
		inserted = binaryResearchD(it + nbr_element - 1, deque.begin() + (nbr_element - 1),end, nbr_element);
		// std::cout << "INSERTED = " << *inserted << std::endl;
		// std::cout<<"petit a inserer :"<<std::distance(min.begin(), it)<<std::endl;
		// std::cout<<"emplacement dans grand a inserer :"<<std::distance(deque.begin(), inserted)<<std::endl;
		deque.insert(inserted, it, it + nbr_element);
		min.erase(it, it + nbr_element);
		index--;
	}
	// std::cout<<"fin d'une eape de recusion\n\n\n";
}

void	PmergeMeDeque::swapD(std::deque<int>::iterator first, std::deque<int>::iterator second, int nbr_ele)
{
	int i = 0;

	while (i < nbr_ele)
	{
		std::swap(*(first - i), *(second - i));
		i++;
	}
}

void	PmergeMeDeque::getMinD(std::deque<int>::iterator &it, int nbr_ele)
{
	int i = 0;
	while (i < nbr_ele)
	{
		// std::cout<<"i == "<<i<<" nbr elem : "<<nbr_ele<<std::endl;
		min.push_back(*it) ;
		it = deque.erase(it);
		i++;
		// std::cout << "PRINT petit dans erase\n";
		// for (std::deque<int>::iterator jit = min.begin(); jit != min.end(); jit++)
		// {
		// 	std::cout << *jit <<  " ";
		// }
		// std::cout<<std::endl;
	}
}

int	PmergeMeDeque::jacobsthalD(int index)
{
	int suite[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	return (suite[index]);
}
std::deque<int>::iterator	PmergeMeDeque::binaryResearchD(std::deque<int>::iterator it, std::deque<int>::iterator start, std::deque<int>::iterator end, int nbr_ele)
{
	int index = ((std::distance(start, end) / nbr_ele) / 2) * nbr_ele;
	std::deque<int>::iterator middle = start + index;
	// std::cout<<"distance midlle = " << std::distance(deque.begin(), middle);
	// std::cout<<  "distance end :"<<std::distance(deque.begin(), end);
	// std::cout<<"distance a inserer :"<<std::distance(min.begin(), it);
	// std::cout<<"distance start  :"<<std::distance(deque.begin(), start)<<std::endl;;

	// std::cout<<"midlle = " << *middle;
	// std::cout<<  "end :"<<*end;
	// std::cout<<" a inserer :"<<*it<<std::endl;
	// std::cout<<"start  :"<<*start;

	if ((*middle) < (*it))
	{
		// std::cout << std::distance(deque.begin(), middle) << std::endl;
		if (middle == end)
			return (middle+1);
		middle += nbr_ele;
		return binaryResearchD(it, middle, end, nbr_ele);
	}
	else
	{
		// std::cout <<"ELSE" <<std::distance(deque.begin(), middle) << std::endl;
		if (middle == start)
		{
			middle -= (nbr_ele-1);
			// std::cout <<"ELSE" <<std::distance(deque.begin(), (middle)) << std::endl;
			// std::cout <<"ELSE" <<*(middle) << std::endl;
			return (middle);
		}
		middle -= nbr_ele;
		return binaryResearchD(it, start, middle, nbr_ele);
	}
	return (it);

}

void PmergeMeDeque::printdequeD()
{
	for (size_t i = 0; i < deque.size(); i++)
	{
		std::cout<<deque[i]<<" ";
	}
	std::cout<<std::endl;
}

bool PmergeMeDeque::isSortedD(int nb_el)
{
	int prev = deque[nb_el-1];
	for (size_t i = nb_el + nb_el-1; i <deque.size();i+=nb_el)
	{
		if (deque[i] < prev)
			return false;
		prev = deque[i];
	}
	return true;
}

void PmergeMeDeque::printGroupsD(int nb_elem)
{
	std::cout<<"{";
	for (size_t i = 0; i < deque.size(); i++)
	{
		if (i > 0 && i%nb_elem == 0)
			std::cout<<"} {";
		std::cout<<deque[i]<<" ";
	}
	std::cout<<"}";
	std::cout<<std::endl;
}


void PmergeMeDeque::printMinGroupsD(int nb_elem)
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
