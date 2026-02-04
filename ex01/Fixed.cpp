/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:25:03 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/04 16:54:36 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
   std::cout << "Int constructor called" << std::endl;
   this->_value = num * (1 << _fractional_bits);
}

Fixed::Fixed(const float num)
{
   std::cout << "Float constructor called" << std::endl;
   this->_value = roundf(num * (1 << _fractional_bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//copy constructor. No need to copy _fractional_bits because it's static
//passing a reference because if passed by value, it would need to
//make a copy using the copy constructor. So infinite recursion
Fixed::Fixed(const Fixed &num)
{
    std::cout << "Copy constructor called" << std::endl;
    // this->_value = num._value;
    *this = num;
}

/*
//copy assignment operator. Called when we write `a = b` with a and b objects
// of Fixed class
//technically possible to pass num by value here, but inefficient to make
//a useless copy
//returns a reference to avoid useless copies (a return by value implies a temp copy)
//also, allows to successfully execute code like `(a = b).setRawBits(0);`. With
//a return by value, the temp copy would have been reset to 0 and not `a`.
*/
Fixed &Fixed::operator=(const Fixed &num)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &num)
        this->_value = num.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}
