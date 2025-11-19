/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:25:10 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/19 08:48:26 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixed_point;
    static const int _fractional_bits;
public:
    Fixed();
    Fixed(const Fixed &old);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    Fixed& operator=(const Fixed & old);
};


#endif
