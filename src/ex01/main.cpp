/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:53:37 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/12 19:57:01 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombies;
	int		numZumbies(7);
	
	zombies = zombieHorde(numZumbies, "Zombie");
	for (int i = 0; i < numZumbies; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}

/*
#include <sstream>

int	main(void)
{
	Zombie *zombies;
	int		numZumbies(7);
	
	
	for (int i = 0; i < numZumbies; i++)
	{
		std::stringstream ss;
		ss << i;
		std::string str = ss.str();
		zombies = zombieHorde(numZumbies, ("Zombie" + str));	
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}
*/