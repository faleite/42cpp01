/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:36:59 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/11 18:43:53 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

/* Utils */
bool	whiteSpaces(const std::string &string);
void	messageError(const std::string& program);

/* replace */
void	replaceFunction(std::string& data, const std::string& str1,
						const std::string& str2);

#endif /* REPLACE_HPP */