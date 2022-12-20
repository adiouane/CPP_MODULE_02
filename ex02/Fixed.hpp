/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:18:40 by adiouane          #+#    #+#             */
/*   Updated: 2022/12/20 22:27:08 by adiouane         ###   ########.fr       */
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
        Fixed &operator=(const Fixed &obj); // it is important to use const here it wont work look in err
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int   toInt(void) const;

             /*--------------------------increment/decrement----------------------------*/

        Fixed & operator ++(void); // prefix incrementation
        Fixed & operator ++(int); // prefix decrementation //todo
        Fixed & operator --(void); // prefix decrementation
        Fixed & operator --(int); // prefix decrementation //todo


        /*---------------------------comparison operators----------------------------*/
        
        bool operator >(Fixed const &f) const; 
        bool operator <(Fixed const &f) const;
        bool operator ==(Fixed const &f) const;
        bool operator!=(Fixed const &f) const;
        bool operator >=(Fixed const &f) const;
        bool operator <=(Fixed const &f) const;

        /*------------------------- arithmetic operators----------------------------*/
        Fixed &operator +(Fixed const &f);
        Fixed &operator -(Fixed const &f);
        Fixed &operator *(Fixed const &f);
        Fixed &operator /(Fixed const &f);

        /*-------------------overloaded member function max min ----------------*/

        /*
            A static member function min that takes as parameters two references on fixed-point
            numbers, and returns a reference to the smallest one.
        */
        Fixed static min(Fixed &f1, Fixed &f2);
        /*
            A static member function min that takes as parameters two references to constant
            fixed-point numbers, and returns a reference to the smallest one.
        */
        Fixed static min(Fixed const &f1, Fixed const &f2);
        /*
            A static member function max that takes as parameters two references on fixed-point
            numbers, and returns a reference to the greatest one.
        */
        Fixed static max(Fixed &f1, Fixed &f2);
        /*
            A static member function max that takes as parameters two references to constant
            fixed-point numbers, and returns a reference to the greatest one
        */
        Fixed static max(Fixed const &f1, Fixed const &f2);

};

std::ostream &operator<<(std::ostream &COUT, Fixed const &obj); // it wont work if you did't use const

#endif