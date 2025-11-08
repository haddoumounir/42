/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:54:49 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/07 20:44:56 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include <iostream>
class Weapon
{
    private:
        std::string type;
    public:
        
        Weapon(std::string name);
        std::string getType();
        void setType(std::string param);
        ~Weapon();
};


#endif