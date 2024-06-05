/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:12 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/05 21:19:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
		return (std::cerr << "Invalid numbers of Zombies" << std::endl, nullptr);
	Zombie *zombies = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return (zombies);
}