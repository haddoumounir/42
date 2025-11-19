/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:24:54 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/19 08:48:24 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed &old)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = old;
    return;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return;
}

int Fixed :: getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(_fixed_point);
}
    
void Fixed:: setRawBits( int const raw )
{
   _fixed_point = raw;
   return;
}

Fixed& Fixed::operator=(const Fixed & old)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if(this != &old)
        this->setRawBits(old.getRawBits());
    return(*this);
}