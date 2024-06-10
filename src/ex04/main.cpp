/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:18:01 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/10 20:27:27 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void	replaceFunction(std::string& data,
							const std::string& str1, const std::string& str2)
{
	size_t pos = data.find(str1);
	while (pos != std::string::npos)
	{
		data = data.substr(0, pos) + str2 + data.substr(pos + str1.length());
		pos = data.find(str1);
	}
}

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
	if (data == "\n")
		fileError("VAZIO!");
	// std::cout << "Dados do Arquivo: \n" << data;
	replaceFunction(data, argv[2], argv[3]);
	// std::cout << "Dados do Replace: \n" << data;
	
	/*
	 * `c_str()` e um metodo da classe std::string em C++ 
	 * retorna um ponteiro para um array de caracteres terminados em null 
	 * (null-terminated character array), que é uma representação em C 
	 * da string armazenada no objeto std::string.
	*/
	std::ofstream outputFile((std::string(argv[1]) + ".replace").c_str());
	outputFile << data;	
	if (!outputFile.eof())
		outputFile << std::endl;
	
	inputFile.close();
	outputFile.close();
	return (0);
}
