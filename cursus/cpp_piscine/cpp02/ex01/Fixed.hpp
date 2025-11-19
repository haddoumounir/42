/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:25:10 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/14 21:03:12 by mhaddou          ###   ########.fr       */
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
};

std::ostream &operator<<(std::ostream &stream, const Fixed & nb);

#endif
