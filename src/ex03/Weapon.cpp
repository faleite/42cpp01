/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:14:12 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/08 17:44:47 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) 
{ 
	this->type = type;
}

Weapon::~Weapon() {}

/**
 * @brief: Este método retorna uma referência constante para o atributo type.
 * Uso: Pode ser chamado em objetos constantes e não constantes de Weapon.
 * Const-Correctness: Garante que o método não pode modificar nenhum membro...
 * da classe (exceto os membros mutable).
 * Modificação do Objeto: O compilador garante que o método não modifica o
 * estado do objeto.
 * 
 * Sem o Uso de `const` no final da linha 32: `getType` so pode ser chamado
 * em objetos não constantes de Weapon.
*/
const std::string& Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(const std::string& newType)
{
	this->type = newType;
}
