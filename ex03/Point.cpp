/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:33:11 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/09 18:59:35 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{

}

Point::Point(const float num_x, const float num_y) : _x(num_x), _y(num_y)
{

}

Point::Point(const Point &point)
{
    *this = point;
}

/*
* this function is required in the OCF, but since `_x` and `_y` are const, 
* they cannot be reassigned anymore. So we `(void) point` to avoid 
* compiler warnings and we simply return `*this`
*/
Point   &Point::operator=(const Point &point)
{
    (void) point;
    return (*this);
}

Point::~Point()
{

}

/*
* returns a `Fixed` object and not a `Fixed const` because:
- it returns a copy so the original object is already protected
- optimizes the compiler
- the caller can decide if the copy of the object is `const` or not

return by value and not by reference because the `Fixed` object is 
simple (`int`). For complex classes it's better to return by const reference.
(const to avoid private members being modified by external functions).
*/
Fixed Point::getX() const
{
    return (this->_x);
}

Fixed Point::getY() const
{
    return (this->_y);
}