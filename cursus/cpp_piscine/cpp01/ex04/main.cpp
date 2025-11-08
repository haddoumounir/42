/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:14:19 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/05 21:37:17 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "main.hpp"

int input_checher(std::string file_path,std::string s1, std::string s2)
{
    if(file_path.empty() || s1.empty()||s2.empty())
    {
        std::cout << "args should not be empty" << std::endl;
        return(1);        
    }
    for (size_t i = 0; i < file_path.size(); i++)
    {
        if(std::isspace(file_path[i]))
        {
            std::cerr << "Incorrect Path Specification" << std::endl;
            return(1);
        }
    }
    return(0);
}

int read_and_replace(std::string file_path, std::string s1, std::string s2)
{
    std::ifstream og_file(file_path.c_str());
    std::string file_path_replace;
    std::string line;
    std::string custom_line;
    
    file_path_replace = file_path + ".replace";
    std::ofstream re_file(file_path_replace.c_str());
    if(!og_file)
    {
        std::cerr << "error while try to open file " + file_path << std::endl;
        return(1);
    }
    while (getline(og_file,line))
    {
        custom_line = "";
        for (size_t i = 0; i < line.size();)
        {
            if(i + s1.size() <= line.size() && line.substr(i,s1.size()) == s1)
                custom_line +=s2, i+=s1.size();
            else
                custom_line +=line[i++];
        }
        re_file << custom_line + "\n";
    }
    return(0);
}

int main(int ac, char **av)
{
    std::string file_path;
    std::string s1;
    std::string s2;
    std::string str;
    
    if(ac != 4)
    {
        std::cerr << "expected file path, src string, and dst string on args\n";
        return(1);
    }
    file_path = av[1];
    s1 = av[2];
    s2 = av[3];
    if(input_checher(file_path,s1,s2))
        return(1);
    return(read_and_replace(file_path,s1,s2));
}
