/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:18:01 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/12 17:38:43 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

/**
 * @brief .c_str() e um metodo da classe std::string 
 * retorna um ponteiro para um array de caracteres terminados em null 
 * (null-terminated character array), que é uma representação em C 
 * da string armazenada no objeto std::string.
 * 
 * @bug DEBUGS:
 * std::cout << "Dados do Arquivo: \n" << data;
 * std::cout << "Dados do Replace: \n" << data;
*/
int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		messageError(argv[0]);
		return (1);
	}
	
	std::ifstream inputFile(argv[1]);
	if (inputFile.fail())
	{
		std::cerr << "Error:\nCould not open " << argv[1] << std::endl;
		return (2);
	}
	
	std::string data, line;
	while (std::getline(inputFile, line))
		data += line + "\n";
	inputFile.close();
	if (whiteSpaces(data))
	{
		std::cerr << "Error:\nEmpty file" << std::endl;
		return (3);
	}
	
	replaceFunction(data, argv[2], argv[3]);
	std::ofstream outputFile((std::string(argv[1]) + ".replace").c_str());
	outputFile << data;
	
	if (outputFile.fail())
	{
		std::cerr << "Error:\nError writing to file" << std::endl;
		return (4);
	}
	outputFile.close();
	return (0);
}
