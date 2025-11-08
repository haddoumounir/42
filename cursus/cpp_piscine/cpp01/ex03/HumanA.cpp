/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:54:36 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/07 20:45:31 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


void HumanA::attack()
{
    std::cout<< name + " attacks with their " + weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA()
{
}

void HumanA::setWeapon(Weapon Weapon)
{
    weapon = Weapon;
}