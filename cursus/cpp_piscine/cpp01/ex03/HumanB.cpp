/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:54:40 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/07 20:45:50 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


void HumanB::attack()
{
    if(weapon)
        std::cout << name + " attacks with their " + weapon->getType() << std::endl;
    else
        std::cout << name + " has no weapon to attack with!" << std::endl;

}
HumanB::HumanB(std::string str) : weapon(NULL)
{
   name.assign(str);
}


void HumanB::setWeapon(Weapon &Weapon)
{
    weapon = &Weapon;
}

HumanB::~HumanB()
{
}