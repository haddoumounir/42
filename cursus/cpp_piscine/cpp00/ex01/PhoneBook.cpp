/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:03:31 by mhaddou           #+#    #+#             */
/*   Updated: 2025/10/26 20:28:51 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

bool PhoneBook::IsValidNumber(std::string Number)
{
	int Index;

	Index = 0;
	if(Number.empty())
		return(false);
	else if(Number.at(Index) == '+')
		Index++;
	while (Index < (int)Number.size())
	{
		if(!std::isdigit(Number.at(Index)))
		{
			std::cerr << "invalid phone number\n";
			return(false);
		}
		Index++;
	}
	if(Number.size() > 1)
		return(true);
	else
	{
		std::cout << "invalid phone number\n";
		return(false);
	}
}
void PhoneBook::PrintWalls(void)
{
	for (short i = 0; i < 4; i++)
		std::cout << "|----------";
	std::cout << "|";
	std::cout << std::endl;
}
bool PhoneBook::GetInput(std::string& str,std::string Message)
{
	if(std::cin.eof())
		return(false);
	std::cout << Message;
	if(!std::getline(std::cin,str))
	{
		std::cout << std::endl;
		return(false);
	}
	while (!str.length())
	{
		std::cout << Message;
		if(!std::getline(std::cin,str))
		{
			std::cout << std::endl;
			return(false);
		}
	}
	return(true);
}
void PhoneBook::PosAndAdd(void)
{
	if(Index == 8)
		Index = 0;
	if(RowNumber != 8)
		RowNumber++;
	TInfo Temp;
	if(!GetInput(Temp.FirstName,"Enter First Name:"))
		return;
	if(!GetInput(Temp.LastName,"Enter Last Name:"))
		return;
	if(!GetInput(Temp.NickName,"Enter Nickname:"))
		return;
	while (true)
	{
		if(!GetInput(Temp.NumberPhone,"Enter Phone Number:"))
			return;
		if(IsValidNumber(Temp.NumberPhone))
			break;
	}
	if(!GetInput(Temp.DarkestSecret,"Enter Darkest Secret:"))
		return;
	Lib[Index].SetData(Temp);
	Index++;
}
void PhoneBook::FormatText(std::string str)
{
	std::string Temp;
	if(str.size() < 10)
		std::cout << "|" << std::setw(10) << str;
	else
	{
		Temp = str.substr(0,9) + ".";
		std::cout << "|" << std::setw(10) << Temp;
	}
}
void PhoneBook::PrintMoreInfo(void)
{
	std::string WannaThisRow;
	int Number = 0;
	int index = 0;
	if(!GetInput(WannaThisRow,"select Index: "))
		return;
	while (WannaThisRow.c_str()[index])
	{
		if(!std::isdigit(WannaThisRow.c_str()[index]))
		{
			std::cerr << "Invalid Number"  << std::endl;
			PrintMoreInfo();
			return;
		}
		index++;
	}
	Number = std::atoi(WannaThisRow.c_str());
	if(Number >= RowNumber)
	{
		std::cerr << "Invalid Number"  << std::endl;
		PrintMoreInfo();
		return;
	}
	std::cout << "First Name: " << Lib[Number].GetData().FirstName << std::endl;
	std::cout << "Last Name: " << Lib[Number].GetData().LastName << std::endl;
	std::cout << "Nick Name: " << Lib[Number].GetData().NickName << std::endl;
	std::cout << "Number Phone: " << Lib[Number].GetData().NumberPhone << std::endl;
	std::cout << "Darkest Secret: " << Lib[Number].GetData().DarkestSecret << std::endl;
}
void PhoneBook::Search(void)
{
	
    std::cout << "SEARCH\n";
    std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nick Name" << "|";
	std::cout << std::endl;
	PrintWalls();
    for (short Pos = 0; Pos < RowNumber; Pos++)
    {
		std::cout << "|" << std::setw(10) << Pos;
		FormatText(Lib[Pos].GetData().FirstName);
		FormatText(Lib[Pos].GetData().LastName);
		FormatText(Lib[Pos].GetData().NickName);
		std::cout << "|";
		std::cout << std::endl;
	   PrintWalls();
    }
	if(!RowNumber)
		return;
	PrintMoreInfo();
   	return;
}

