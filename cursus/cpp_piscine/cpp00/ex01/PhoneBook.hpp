/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:03:41 by mhaddou           #+#    #+#             */
/*   Updated: 2025/10/26 20:45:03 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:
    Contact Lib[8];
    short Index = 0;
    short RowNumber = 0;
    public:
        void PosAndAdd(void);
        void Search(void);
        bool GetInput(std::string& str,std::string Message);
        void PrintWalls(void);
        bool IsValidNumber(std::string Number);
        void FormatText(std::string str);
        void PrintMoreInfo(void);
};  
#endif