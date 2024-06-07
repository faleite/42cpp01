/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:46:06 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/07 16:53:22 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(/* args */);
		~Weapon();
		getType(const std::string &type);
		setType(const std::string &type);
};

Weapon::Weapon(/* args */)
{
}

Weapon::~Weapon()
{
}
 Weapon{
	
}

#endif // WEAPON_HPP 