/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:54:47 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/03 15:02:03 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void Weapon::setType(std::string param)
{
    type = param;
}
std::string Weapon::getType()
{
    return(type);
}
Weapon::Weapon(std::string name)
{
    setType(name);
}

Weapon::~Weapon()
{
}