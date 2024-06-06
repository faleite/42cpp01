/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:33:15 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/06 16:58:43 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
* Outra Opcao:
* @brief como string é uma variável do tipo std::string, o operador
* << tem uma sobrecarga que imprime o conteúdo da string em
* vez do endereço. Para contornar isso, você pode usar um cast
* para imprimir o endereço como um ponteiro void:
* 
* @ref std::cout << static_cast<void*>(&string) << std::endl;
*/
int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "Memory address:" << std::endl;;
	std::cout << "The memory address of the string variable.: ";
	std::cout << &string << std::endl;

	std::cout << "The memory address held by stringPTR......: ";
	std::cout << stringPTR << std::endl;

	std::cout << "The memory address held by stringREF......: ";
	std::cout << &stringREF << std::endl;

	std::cout << "String values:" << std::endl;;
	std::cout << "The value of the string variable..: ";
	std::cout << string << std::endl;

	std::cout << "The value pointed to by stringPTR.: ";
	std::cout << *stringPTR << std::endl;

	std::cout << "The value pointed to by stringREF.: ";
	std::cout << stringREF << std::endl;
}
