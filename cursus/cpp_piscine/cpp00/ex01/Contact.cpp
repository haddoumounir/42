/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:52:29 by mhaddou           #+#    #+#             */
/*   Updated: 2025/10/26 20:29:14 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::SetData(TInfo temp)
{
	data.FirstName = temp.FirstName;
	data.LastName = temp.LastName;
	data.NickName = temp.NickName;
	data.NumberPhone = temp.NumberPhone;
	data.DarkestSecret = temp.DarkestSecret;
}
TInfo Contact::GetData(void)
{
	return(data);
}

