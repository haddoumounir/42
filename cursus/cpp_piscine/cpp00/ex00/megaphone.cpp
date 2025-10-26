/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:17:56 by mhaddou           #+#    #+#             */
/*   Updated: 2025/10/26 20:27:24 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        std::string str;
        for (int i = 1; i < ac; i++)
        {
            str = av[i];
            for(int j = 0; str[j] != '\0';j++)
            {
                if(islower(str[j]))
                    str[j] -=32;
            }
            std::cout << str;
        }
        std::cout << std::endl;
    }
    return(0);
}