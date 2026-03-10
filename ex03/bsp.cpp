/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:33:30 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/10 12:01:24 by michel_32        ###   ########.fr       */
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

/**
 * @brief Determines if a point lies strictly inside a triangle using barycentric coordinates.
 * 
 * This function checks whether the given point is strictly contained within the triangle
 * formed by vertices a, b, and c. It uses the area method: if the point is inside the
 * triangle, the sum of the areas of the three sub-triangles (formed by the point and
 * each pair of vertices) equals the area of the original triangle.
 * 
 * @param a The first vertex of the triangle.
 * @param b The second vertex of the triangle.
 * @param c The third vertex of the triangle.
 * @param point The point to test.
 * 
 * @return true if the point is strictly inside the triangle (not on the edges or vertices),
 *         false if the point is on the boundary or outside the triangle.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed area_ABC = calculateArea(a, b, c);
    Fixed area_APC = calculateArea(a, point, c);
    Fixed area_BPC = calculateArea(b, point, c);
    Fixed area_APB = calculateArea(a, point, b);

    if (area_APC == 0 || area_BPC == 0 || area_APB == 0) // the point is on an edge or a vertex
        return (false);
    return (area_ABC == area_APC + area_BPC + area_APB);
}