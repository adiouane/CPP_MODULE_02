/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:18:40 by adiouane          #+#    #+#             */
/*   Updated: 2022/12/20 22:44:23 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed{
    private:
        int value; // An integer to store the fixed-point number value.
        static const int fractionalBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int _value);
        Fixed(const float numbr);
        Fixed(const Fixed&obj);
        Fixed &operator=(const Fixed &obj);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int   toInt(void) const;

};

std::ostream &operator<<(std::ostream &COUT, Fixed const &obj); // it wont work if you did't use const // todo

#endif