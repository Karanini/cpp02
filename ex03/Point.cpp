/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:33:11 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/09 18:06:45 by michel_32        ###   ########.fr       */
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