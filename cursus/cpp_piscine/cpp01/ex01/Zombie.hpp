/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:54:44 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/08 11:19:41 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
class Zombie
{
private:
    std::string _name;
public:
    Zombie();
    void setName(std::string name);
    ~Zombie();
    void announce();
};
Zombie* zombieHorde( int N, std::string name );
#endif