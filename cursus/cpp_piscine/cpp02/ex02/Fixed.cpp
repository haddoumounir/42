/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:24:54 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/19 08:59:49 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() 
{
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
    return;
}

Fixed::Fixed(int nb) :  _fixed_point(nb << _fractional_bits)
{
    std::cout << "Int constructor called" << std::endl;
   
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


Fixed::Fixed(float nb) : _fixed_point(roundf(nb * (1 << _fractional_bits)))
{
    std::cout << "Float constructor called" << std::endl;
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
    stream << nb.toFloat();
    return (stream);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (_fixed_point > other._fixed_point);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (_fixed_point < other._fixed_point);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (_fixed_point >= other._fixed_point);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (_fixed_point <= other._fixed_point);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (_fixed_point == other._fixed_point);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (_fixed_point != other._fixed_point);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (Fixed(toFloat() / other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(toFloat() * other.toFloat()));
}

Fixed& Fixed::operator++()
{
    this->_fixed_point++;
    return(*this);
}

Fixed& Fixed::operator--()
{
    _fixed_point--;
    return(*this);
}

Fixed Fixed::operator++(int)
{
     Fixed tmp(*this);
    _fixed_point++;
    return(tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    setRawBits(_fixed_point--);
    return(tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

