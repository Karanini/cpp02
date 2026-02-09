/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:32:56 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/09 19:07:52 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point();
    Point(const float num_x, const float num_y);
    Point(const Point &point);
    Point   &operator=(const Point &point);
    ~Point();
    Fixed getX() const;
    Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
static Fixed calculateArea(Point const a, Point const b, Point const c);

#endif