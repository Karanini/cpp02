/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:25:03 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/02 15:50:54 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//copy constructor. No need to copy _bits because it's static
Fixed::Fixed(const Fixed &num)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_value = num._value;
}

//copy assignment operator. Called when we write "a = b" with a and b objects
// of Fixed class
Fixed &Fixed::operator=(const Fixed &num)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = num._value;
    return (*this);
}