/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doublevv <vv>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:42:32 by doublevv          #+#    #+#             */
/*   Updated: 2025/09/16 11:19:47 by doublevv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <stdlib.h>

class BitcoinExchange
{
	public:
		BitcoinExchange(){};
		~BitcoinExchange(){};
		BitcoinExchange &operator=(const BitcoinExchange &rhs)
		{
			(void)rhs;
			return (*this);
		};
		BitcoinExchange(const BitcoinExchange &obj)
		{
			(*this) = obj;
		};
		void	searching(std::string file);
		void	getCsv(std::string file);
		bool	dateValid(std::string date);

	private:
		std::map<std::string, float> dataBit;

};

#endif
