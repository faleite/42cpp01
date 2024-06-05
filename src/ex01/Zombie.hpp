/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:09:03 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/05 21:03:02 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void announce( void );
		void setName( std::string name );
};

Zombie* zombieHorde( int N, std::string name );

#endif /* ZOMBIE_HPP */