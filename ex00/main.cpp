/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doublevv <vv>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:18:08 by doublevv          #+#    #+#             */
/*   Updated: 2025/09/15 17:08:59 by doublevv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange	instance;
	std::ifstream	file(av[1]);

	if (ac != 2)
	{
		std::cout << "you must take a file as an argument" << std::endl;
		return (1);
	}
	try
	{
		instance.getCsv("data.csv");
		instance.searching(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
