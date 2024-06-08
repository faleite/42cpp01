/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:09:03 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/08 14:31:46 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

/**
 * Declarar variáveis como private e métodos como public é uma prática
 * recomendada e comumente seguida na programação orientada a objetos. 
 * Isso promove encapsulamento, proteção de dados, abstração e facilidade
 * de manutenção.
*/
class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif /* ZOMBIE_HPP */