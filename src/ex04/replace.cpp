/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:36:59 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/13 17:45:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	replaceFunction(std::string& data, const std::string& str1,
						const std::string& str2)
{
	size_t pos = data.find(str1);
	std::string replace("");
	while (pos != std::string::npos && !data.empty())
	{
		replace += data.substr(0, pos) + str2; 
		data = data.substr(pos + str1.length());
		pos = data.find(str1);
	}
	data = replace + data;
}

bool	whiteSpaces(const std::string &string)
{
	for (size_t i = 0; i < string.size(); ++i)
	{
		if (!std::isspace(string[i]))
			return (false);
	}
	return (true);
}

void	messageError(const std::string& program)
{
	std::cerr << "Invalid use!" << std::endl;
	std::cout << "Try: " << program;
	std::cout << " <filename> <string1> <string2>" << std::endl;
}