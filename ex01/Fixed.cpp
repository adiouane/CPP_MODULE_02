/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:18:42 by adiouane          #+#    #+#             */
/*   Updated: 2022/12/20 22:41:30 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void){
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed&obj){

    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj){
    std::cout << "Copy assignment operator called" << std::endl;
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
    this->value = roundf(numbr * (/*256*/ 1 << this->fractionalBits)); // this shift right
}

float Fixed::toFloat(void) const{
    return(float)(this->value) / (/*256*/ 1 << this->fractionalBits);
}

int   Fixed::toInt(void) const{
    return(this->value / (/*256*/ 1 << this->fractionalBits));
}

std::ostream &operator<<(std::ostream &COUT, Fixed const &obj){
    COUT << obj.toFloat();
      return(COUT);
}
