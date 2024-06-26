/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:31:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/12 17:18:34 by faaraujo         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	Harl harl;
	
	if (argc == 2)
	{
		std::cout << StringUppercase(argv[1]) << ":" << std::endl;
		harl.complain(StringUppercase(argv[1]));
		return (0);
	}
	else
	{
		std::cout << "Insert one level "; 
		std::cout << "(DEBUG, INFO, WARNING or ERROR):" << std::endl;
		std::string level;
		if (!std::getline(std::cin, level))
			return (1);
		harl.complain(StringUppercase(level));
	}
	return (0);
}
