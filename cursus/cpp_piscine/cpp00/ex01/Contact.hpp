/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:41:03 by mhaddou           #+#    #+#             */
/*   Updated: 2025/10/26 20:30:17 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>

typedef struct SInfo
{
    std::string FirstName;
    std::string LastName;
    std::string NumberPhone;
    std::string NickName;
    std::string DarkestSecret;
} TInfo;

class Contact
{
    private:
        TInfo data;
    public:
        void SetData(TInfo data);
        TInfo GetData(void);
};
#endif
