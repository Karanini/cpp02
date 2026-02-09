/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:33:30 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/09 18:51:25 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed calculateArea(Point const a, Point const b, Point const c)
{
    // The result depends on whether vertices are clockwise or counter-clockwise
    Fixed res = (a.getX() * (b.getY() - c.getY()) +
                 b.getX() * (c.getY() - a.getY()) +
                 c.getX() * (a.getY() - b.getY())) / 2;
    // Return absolute value to get the geometric area magnitude
    return (res < 0) ? res * -1 : res;
}