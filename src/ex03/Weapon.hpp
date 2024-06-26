/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:46:06 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/08 15:38:35 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string& getType() const;
		void setType(const std::string& newType);
	private:
		std::string	type;
};

#endif // WEAPON_HPP 