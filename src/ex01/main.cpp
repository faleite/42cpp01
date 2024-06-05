/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:53:37 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/05 21:15:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombies;
	int		numZumbies(-1);
	
	zombies = zombieHorde(numZumbies, "Zombie");
	for (int i = 0; i < numZumbies; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}