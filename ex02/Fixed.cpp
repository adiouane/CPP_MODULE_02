/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:18:42 by adiouane          #+#    #+#             */
/*   Updated: 2022/12/20 23:19:45 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void){
    this->value = 0;
}

Fixed::~Fixed(void){
}

Fixed::Fixed(const Fixed&obj){
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj){
    this->value = obj.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const{
    return(this->value);
}

void    Fixed::setRawBits(int const raw){
    this->value = raw;
}

/*---ADDED--*/


Fixed::Fixed(const int _value){
    this->value = _value * (/*256*/ 1 << this->fractionalBits); // it like you multiplying 8  by 2^8 which is 256. this shift left
}

Fixed::Fixed(const float numbr){
    this->value = roundf(numbr * (/*256*/ 1 << this->fractionalBits));
}

float Fixed::toFloat(void) const{
    return(float)(this->value) / (/*256*/ 1 << this->fractionalBits); // shift right
}

int   Fixed::toInt(void) const{
    return(this->value / (/*256*/ 1 << this->fractionalBits)); // shift right
}

std::ostream &operator<<(std::ostream &COUT, Fixed const &obj){
    COUT << obj.toFloat();
      return(COUT);
}


/*--------------------------increment/decrement----------------------------*/

Fixed &Fixed::operator ++(void)
{
    // case 1: ++a
    this->value++;
    return *this;
}

Fixed &Fixed::operator --(void)
{
    // case 1: --a 
    this->value--;
    return *this;
}

Fixed &Fixed::operator ++(int){
    // case 2: a++
    Fixed *tmp = new Fixed(*this);
    this->value++;
    return *tmp;
}

Fixed &Fixed::operator --(int){
    // case 2: a--
    Fixed *tmp = new Fixed(*this);
    this->value--;
    return *tmp;
}

/*------------------------- arithmetic operators----------------------------*/


Fixed &Fixed::operator +(Fixed const& obj)
{
    this->value += obj.value;
    return *this;
}

Fixed &Fixed::operator *(Fixed const& obj)
{
    this->value *= obj.value;
    this->value >>= this->fractionalBits;
    return *this;
}

Fixed &Fixed::operator /(Fixed const& obj)
{
    this->value /= obj.value;
    this->value <<= this->fractionalBits;
    return *this;
}

Fixed &Fixed::operator -(Fixed const& obj)
{
    this->value -= obj.value;
    return *this;
}


/*---------------------------comparison operators----------------------------*/

bool Fixed::operator>(Fixed const& obj) const
{
    return this->value > obj.value;
}

bool Fixed::operator<(Fixed const& obj) const
{
    return this->value < obj.value;
}

bool Fixed::operator==(Fixed const& obj) const
{
    return this->value == obj.value;
}

bool Fixed::operator!=(Fixed const& obj) const
{
    return this->value != obj.value;
}

bool Fixed::operator>=(Fixed const& obj) const
{
    return this->value >= obj.value;
}

bool Fixed::operator<=(Fixed const& obj) const
{
    return this->value <= obj.value;
}

//A static member function max() that takes two references to Fixed objects and returns a reference to the Fixed object with the highest value.

Fixed Fixed::max(Fixed const& f1, Fixed const& f2)
{
    return f1 > f2 ? f1 : f2;
}

Fixed Fixed::max(Fixed & f1, Fixed & f2)
{
    return f1 > f2 ? f1 : f2;
}

Fixed Fixed::min(Fixed const& f1, Fixed const& f2)
{
    return f1 < f2 ? f1 : f2;
}

Fixed Fixed::min(Fixed & f1, Fixed & f2)
{
    return f1 < f2 ? f1 : f2;
}