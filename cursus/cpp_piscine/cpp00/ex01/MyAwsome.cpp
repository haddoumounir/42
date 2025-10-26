/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwsome.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:09:55 by mhaddou           #+#    #+#             */
/*   Updated: 2025/10/26 20:44:53 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

int main(void)
{
    std::string Cmd;
    PhoneBook Book;
    
    while (1337)
    {
        if(!Book.GetInput(Cmd,"enter command (ADD, SEARCH,EXIT): "))
            return(1);
        if(Cmd == "ADD")
            Book.PosAndAdd();
        else if (Cmd == "SEARCH")
            Book.Search();
        else if(Cmd == "EXIT")
            break;
    }
    std::cout << "the contacts are lost forever :)\n";
    return(0);
}
