/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:21:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/05 20:50:35 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie( std::string name )
{
	this->name = name;
}

void Zombie::setName( std::string name )
{
	this->name = name;
}

void Zombie::announce( void )
{
	std::cout << name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name <<" died..." << std::endl;
}
