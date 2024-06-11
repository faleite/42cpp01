/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:34:39 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/11 20:56:00 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain( std::string level )
{
	std::string	msgLevel[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	void (Harl::*ptrForMessages[4])(void) = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	for (size_t i = 0; i < 4; i++)
	{
		if (!msgLevel[i].compare(level))
		{
			(this->*ptrForMessages[i])();
			break ;
		}
		if (i == 4)
			std::cerr << "Error: Invalid complain level!" << std::endl;
	}
}