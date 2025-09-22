/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doublevv <vv>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:50:24 by doublevv          #+#    #+#             */
/*   Updated: 2025/09/22 13:08:27 by doublevv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	BitcoinExchange::getCsv(std::string file)
{
	std::ifstream filedata(file.c_str());

	if (!filedata.is_open())
	{
		std::cout << "cannot open file\n";\
		return ;
	}
	std::string data;
	while (getline(filedata, data, '\n'))
	{
		char *pend;
		size_t pos = data.find(',');
		std::string date = data.substr(0, pos);
		float	price = strtof(data.substr(pos + 1, '\n').c_str(), &pend);
		this->dataBit[date] = price;
	}
	filedata.close();
}

bool	BitcoinExchange::dateValid(std::string date)
{
	for (size_t i = 0; i < date.size(); i++)
	{
		if (date[4] != '-' || date[7] != '-')
		{
			std::cout << "SIZE = " << date.size() << std::endl;
			std::cout << "I = " << i << std::endl;
			return (false);
		}
	}
	std::cout << "DATE HERE " << date << std::endl;
	int year = atoi((date.substr(0, 4)).c_str());
	int month = atoi((date.substr(5, 6)).c_str());
	int day = atoi((date.substr(8, 9)).c_str());

	if ((year < 2008 || year > 2025) || (month < 1 || month > 12) || (month == 2 && day > 28) || day < 1 || (month % 2 == 0 && day > 31) || (month % 2 == 1 && day > 30 ))
	{
		std::cout << "ERROROOOO\n";
		return (false);
	}
	return (true);
}

void	BitcoinExchange::searching(std::string file)
{
	std::ifstream filedata(file.c_str());
	std::string data;
	size_t pos;
	std::string date;
	std::string value;
	char *pend;

	if (!filedata.is_open())
	{
		std::cout << "cannot open file\n";
		return ;
	}
	std::getline(filedata, data);
	std::cout << "DATA = " << data << std::endl;
	if(data != "date | value")
	{
		std::cout << "header missing\n";
		return ;
	}
	while (std::getline(filedata, data, '\n'))
	{
		pos = data.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "empty file\n";
		}
		else
			date = data.substr(0, pos);
		std::cout << "\n";
		if (!dateValid(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return ;
		}
		float	value = strtof(data.substr(pos + 1, '\n').c_str(), &pend);
		if (value < 0)
			std::cout << "Error: not a positive number.\n";
		if (value > 1000)
			std::cout << "Error: too large a number.\n";
		std::map<std::string, float>::iterator it = dataBit.find(date);
		it = dataBit.upper_bound(date);
		--it;
		if (it != dataBit.end())
			std::cout << it->first << "=> " << value << " = " << it->second * value << std::endl;
	}
}
