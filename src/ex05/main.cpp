/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:31:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/11 20:59:09 by faaraujo         ###   ########.fr       */
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
	
	if (argc != 2)
	{
		std::cout << "Use: " << argv[0] << " level" << std::endl;
		std::cout << "Insert one complain:" << std::endl; 
		std::cout << "DEBUG\nINFO\nWARNING\nERROR" << std::endl;
		return (1);
	}
	
	harl.complain(StringUppercase(argv[1]));
	return (0);
}