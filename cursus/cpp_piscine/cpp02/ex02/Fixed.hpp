/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:25:10 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/19 08:58:11 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>
class Fixed
{
private:
    int _fixed_point;
    static const int _fractional_bits;
public:
    Fixed(float nb);
    float toFloat( void ) const;
    int toInt( void ) const;
    Fixed(const Fixed &old);
    ~Fixed();
    Fixed(int nb);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    Fixed& operator=(const Fixed & old);
    Fixed();
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    static Fixed& min(Fixed &a, Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &stream, const Fixed & nb);

#endif
