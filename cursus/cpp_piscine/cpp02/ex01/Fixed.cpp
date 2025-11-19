/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:24:54 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/19 08:50:50 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(int nb)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(nb << _fractional_bits);
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


Fixed::Fixed(float nb)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf(nb * (1 << _fractional_bits)));
}

float Fixed::toFloat( void ) const
{
    return((float)_fixed_point / (1 << _fractional_bits));
}

int Fixed::toInt( void ) const
{
    return(_fixed_point >> _fractional_bits);
}

std::ostream &operator<<(std::ostream &stream, const Fixed & nb)
{
    return (stream << nb.toFloat());
}