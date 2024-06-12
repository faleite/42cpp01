/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:31:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/12 19:07:27 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string	StringUppercase(const std::string &str)
{
	std::string	converted = str;
	for (std::string::size_type i = 0; i < converted.size(); ++i)
		converted[i] = std::toupper(converted[i]);
	return (converted);
}

int	getLevel(std::string level)
{
	if (level.compare("DEBUG") == 0)
		return (1);
	if (level.compare("INFO") == 0)
		return (2);
	if (level.compare("WARNING") == 0)
		return (3);
	if (level.compare("ERROR") == 0)
		return (4);
	return (5);
}

int	main(int argc, char *argv[])
{
	Harl harl;
	
	if (argc != 2)
	{
		std::cerr << "Use: " << argv[0] << " MessageLevel "; 
		std::cerr << "(DEBUG, INFO, WARNING or ERROR)" << std::endl;
		return (1);
	} 
	std::string level = StringUppercase(argv[1]);
	int lvl = getLevel(level);
	switch (lvl)
	{
		case 1:
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 2:
			harl.complain("INFO");
			std::cout << std::endl;
		case 3:
			harl.complain("WARNING");
			std::cout << std::endl;
		case 4:
			harl.complain("ERROR");
			std::cout << std::endl;
			break ;
		default:
			harl.complain("DEFAULT");
	}
	return (0);
}
