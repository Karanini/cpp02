/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:33:30 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/09 19:04:45 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
The result sign depends on whether vertices are clockwise (negative) 
or counter-clockwise (positive).
Return absolute value to get the geometric area magnitude
* 
*/
static Fixed calculateArea(Point const a, Point const b, Point const c)
{
    Fixed res = (a.getX() * (b.getY() - c.getY()) +
                 b.getX() * (c.getY() - a.getY()) +
                 c.getX() * (a.getY() - b.getY())) / 2;
    if (res < 0)
        return (res * -1);
    else
        return (res);
}