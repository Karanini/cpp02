/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:33:30 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/09 19:13:44 by michel_32        ###   ########.fr       */
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

/*
* `if (area_APC == 0 || area_BPC == 0 || area_APB == 0)` means that the point
* is on an edge or a vertex so return `false`
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed area_ABC = calculateArea(a, b, c);
    Fixed area_APC = calculateArea(a, point, c);
    Fixed area_BPC = calculateArea(b, point, c);
    Fixed area_APB = calculateArea(a, point, b);

    if (area_APC == 0 || area_BPC == 0 || area_APB == 0)
        return (false);
    return (area_ABC == area_APC + area_BPC + area_APB);
}