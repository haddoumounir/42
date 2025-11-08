/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:54:38 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/08 11:24:59 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static int zombies(std::string str, std::string size)
{
    Zombie *horde;
    int nb;
    
    nb = std::atoi(size.c_str());
    if(nb > __INT_MAX__ || nb <= 0)
    {
        std::cerr << "use number between 1 and " << __INT_MAX__ << std::endl;
        return(1);
    }
    try
    {
        horde = zombieHorde(nb,str);
        for(int index = 0; index < nb; index++)
            horde[index].announce();
        delete [] horde;
    }
    catch(const std::bad_alloc& error)
    {
        std::cerr << error.what() << std::endl;
    }
    return(0);
}

int main(int ac, char **av)
{
    std::string name;
    std::string size;
    
    if(ac != 3)
    {
        std::cerr << "one arg for names and  one for size" << std::endl;
        return(1);
    }
    else
    {
        name = av[1];
        size = av[2];
        if(name.empty() || size.empty())
            return(std::cerr << "args must not be empty" <<std::endl ,1);
        for (size_t i = 0; i < size.size(); i++)
        {
            if(!std::isdigit(size[i]))
            {
                std::cerr << "Size must be numeric :)" << std::endl;
                return(1);
            }
        }
    }
    return(zombies(name,size));
}
