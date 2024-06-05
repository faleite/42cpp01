/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:53:37 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/05 19:55:01 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	stackZombie = Zombie("Stack Zombie");
	Zombie*	heapZombie[3];
	const std::string names[] {"01 Zombie", "02 Zombie", "03 Zombie"};

	stackZombie.announce();
	std::cout << "\n";
	for (size_t i = 1; i < 4; i++)
	{
		std::cout << 0 << i << " ";
		heapZombie[i] = newZombie("Heap Zombie");
		heapZombie[i]->announce();
		delete heapZombie[i];
	}
	std::cout << "\n";
	for (size_t i = 0; i < 3; i++)
		randomChump(names[i]);
	std::cout << "\n";
	return (0);
}