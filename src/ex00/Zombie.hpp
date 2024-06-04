/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:09:03 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/04 21:05:19 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

/**
 * Resources
 * https://github.com/Elli-v/42_C04_CPP_Module/tree/master/CPP_Module_01/ex00
 * https://velog.io/@soooh_42/42Seoul-CPP-Module-01-ex00
 * https://velog.io/@soooh_42/posts?tag=cpp
*/
class Zombie
{
	private:
		std::string name;
	public:
		Zombie(); // Zombie( void );
		Zombie( std::string name );
		~Zombie();
		void announce( void );
};

// Zombie* newZombie( std::string name );
// void randomChump( std::string name );

#endif /* ZOMBIE_HPP */