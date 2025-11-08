/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:54:42 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/08 11:19:45 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    
};
void  Zombie:: announce( void )
{
    std::cout << _name + ": BraiiiiiiinnnzzzZ...\n";
}
void Zombie::setName(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie:  " << _name + " is destroyed\n";
}
