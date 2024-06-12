/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:34:39 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/12 19:06:32 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my";
	std::cout << "XL-double-cheese-triple-pickle-special-ketchup burger.\n";
	std::cout << "I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "Adding extra bacon costs more money.\nYou didn’t put enough ";
	std::cout << "bacon in my burger!\nIf you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming for years whereas you started working";
	std::cout << "here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
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
			std::cout << "[ " << level << " ]" << std::endl; 
			(this->*ptrForMessages[i])();
			break ;
		}
		if (i == 3)
		{
			std::cerr << "[ Probably complaining about insignificant problems";
			std::cerr << " ]" << std::endl;	
		}
	}
}
