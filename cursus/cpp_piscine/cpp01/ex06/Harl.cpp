/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:01:58 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/07 21:15:39 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


void Harl::debug(void)
{
    std::cerr << "[DEBUG]I love having extra BOCA, I really do! :)" << std::endl;
}

void Harl::info(void)
{
    std::cerr << "[INFO]You didn't putenough sause in my BOCA! :>" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]I think I deserve to have some extra BOCA for free ^_^" << std::endl;
}

void Harl::error(void)
{
    std::cerr << "[ERROR]This is unacceptable :( ! mini BOCA :} ? I want to speak to owner now *_*" << std::endl;
}

void Harl::complain(std::string level)
{
    size_t i;
    std::string arr[] = {"DEBUG", "INFO", "WARNING", "ERROR" };

    i = 0;
    while (i < 4)
    {
        if(arr[i] == level)
            break;
        i++;
    }
   switch (i)
   {
   case 0:
    debug();
    break;
   case 1:
    info();
    break;
   case 2:
    warning();
    break;
   case 3:
    error();
    break;
   default:
    std::cerr << "[UNKNOWN] Invalid level!" << std::endl;
   }
}

Harl::Harl()
{
    
}

Harl::~Harl()
{
    
}