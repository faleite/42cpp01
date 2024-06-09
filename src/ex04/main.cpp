/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:18:01 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/09 16:46:56 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

// std::string	replaceFunction(const std::string filename)
// {
// }

void	messageError(const std::string& program)
{
	std::cerr << "Invalid use!" << std::endl;
	std::cout << "Try: " << program;
	std::cout << " <filename> <string1> <string2>" << std::endl;
	exit(1);
}
void	fileError(const std::string& file)
{
	std::cerr << "Error: Could not open " << file << std::endl;
	exit(1);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		messageError(argv[0]);
	std::string fileReplace = std::string(argv[1]) + ".replace";
	std::fstream inputFile(argv[1]);
	if (!inputFile)
		fileError(argv[1]);
	std::string data, line;
	while (std::getline(inputFile, line))
		data += line + "\n";
	std::cout << "Dados do Arquivo: \n" << data;
	inputFile.close();
	std::ofstream outputFile(std::string(argv[1]) + ".replace");
	return (0);
}
