/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:25:03 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/06 15:56:47 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/*
* initializes a Fixed number with an int. To do so we need to shift the fractional
* part of the number into the integer part
* with `1 << _fractional_bits`, we shift 1 by 8 bits (`_fractional_bits == 8`).
* It means we multiply by 2^8 = 256 the `num` passed as a parameter.
*/
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
// The compiler understands this != &num because we are comparing pointers,
not the objects themselves.
*/
Fixed &Fixed::operator=(const Fixed &num)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &num)
        this->_value = num.getRawBits();
    return (*this);
}

/*
* this function must be a non-member one, because in C++, the left-hand operand
of a member operator function must be an instance of the class it belongs to.
This weird sentence means that if operator<<() would have been a member function,
the syntax to use would be `Fixed << std::cout;`, but we want to implement the
standard `std::cout << Fixed;`
*/
std::ostream &operator<<(std::ostream &output, Fixed const &i)
{
	output << i.toFloat();
	return (output);
}

bool	Fixed::operator>(const Fixed &num) const
{
	return (this->toFloat() > num.toFloat());
}

bool	Fixed::operator<(const Fixed &num) const
{
	return (this->toFloat() < num.toFloat());
}

bool	Fixed::operator>=(const Fixed &num) const
{
	return (this->toFloat() >= num.toFloat());
}

bool	Fixed::operator<=(const Fixed &num) const
{
	return (this->toFloat() <= num.toFloat());
}

bool	Fixed::operator==(const Fixed &num) const
{
	return (this->toFloat() == num.toFloat());
}

bool	Fixed::operator!=(const Fixed &num) const
{
	return (this->toFloat() != num.toFloat());
}

Fixed Fixed::operator+(const Fixed &num)
{
	Fixed	added;

	added.setRawBits(this->toFloat() + num.toFloat());
	return (added);
}

Fixed Fixed::operator-(const Fixed &num)
{
	Fixed	substracted;

	substracted.setRawBits(this->toFloat() - num.toFloat());
	return (substracted);
}

Fixed Fixed::operator*(const Fixed &num)
{
	Fixed	multiplied;

	multiplied.setRawBits(this->toFloat() * num.toFloat());
	return (multiplied);
}

Fixed Fixed::operator/(const Fixed &num)
{
	Fixed	divided;

	divided.setRawBits(this->toFloat() / num.toFloat());
	return (divided);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << _fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() / (1 << _fractional_bits));
}
