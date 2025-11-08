/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:33:15 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/05 21:20:44 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
    std::string name;
    Zombie *zoombie;
    
    if(ac != 2)
    {
        std::cerr << "should be only one arg that represents zombie name\n";
        return(1);
    }
    name = av[1];
    if(name.empty())
    {
        std::cerr << "Name should not be empty\n";
        return(1);
    }
    try
    {
        zoombie = newZombie(name);
        zoombie->announce();
        delete zoombie;
    }
    catch(std::bad_alloc& error)
    {
        std::cerr << error.what() << '\n';
        randomChump(name);
    }
    return(0);
}