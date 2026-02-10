/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:24:50 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/10 09:47:38 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

void test_bsp(Point const a, Point const b, Point const c, Point const point, std::string const &name, bool expected)
{
    bool result = bsp(a, b, c, point);
    std::cout << "Test " << name << ": ";
    if (result == expected)
        std::cout << "\033[32mOK\033[0m";
    else
        std::cout << "\033[31mKO\033[0m";
    std::cout << " (Expected: " << (expected ? "True" : "False") << ", Got: " << (result ? "True" : "False") << ")" << std::endl;
}

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    std::cout << "--- Triangle: A(0,0), B(10,0), C(0,10) ---" << std::endl;

    std::cout << "\n[Inside Points]" << std::endl;
    test_bsp(a, b, c, Point(1, 1), "Point(1, 1)", true);
    test_bsp(a, b, c, Point(3, 3), "Point(3, 3)", true);
    test_bsp(a, b, c, Point(0.5f, 0.5f), "Point(0.5, 0.5)", true);
    test_bsp(a, b, c, Point(1, 8), "Point(1, 8)", true);

    std::cout << "\n[Outside Points]" << std::endl;
    test_bsp(a, b, c, Point(11, 0), "Point(11, 0)", false);
    test_bsp(a, b, c, Point(0, 11), "Point(0, 11)", false);
    test_bsp(a, b, c, Point(-1, -1), "Point(-1, -1)", false);
    test_bsp(a, b, c, Point(10, 10), "Point(10, 10)", false);
    test_bsp(a, b, c, Point(5, 6), "Point(5, 6)", false);

    std::cout << "\n[Edge Points (Should be False)]" << std::endl;
    test_bsp(a, b, c, Point(5, 0), "Point(5, 0) [AB edge]", false);
    test_bsp(a, b, c, Point(0, 5), "Point(0, 5) [AC edge]", false);
    test_bsp(a, b, c, Point(5, 5), "Point(5, 5) [BC edge]", false);

    std::cout << "\n[Vertex Points (Should be False)]" << std::endl;
    test_bsp(a, b, c, Point(0, 0), "Point(0, 0) [Vertex A]", false);
    test_bsp(a, b, c, Point(10, 0), "Point(10, 0) [Vertex B]", false);
    test_bsp(a, b, c, Point(0, 10), "Point(0, 10) [Vertex C]", false);

    std::cout << "\n[Edge Cases]" << std::endl;
    test_bsp(a, b, c, Point(0.01f, 0.01f), "Point(0.01, 0.01) [Very close]", true);
    test_bsp(a, b, c, Point(-0.01f, -0.01f), "Point(-0.01, -0.01) [Very close outside]", false);
    test_bsp(a, b, c, Point(4.99f, 4.99f), "Point(4.99, 4.99) [Just inside hypotenuse]", true);
    test_bsp(a, b, c, Point(5.01f, 5.01f), "Point(5.01, 5.01) [Just outside hypotenuse]", false);

    std::cout << "\n--- Triangle with Negative Coordinates: A(-5,-5), B(5,-5), C(0,5) ---" << std::endl;
    Point d(-5, -5);
    Point e(5, -5);
    Point f(0, 5);
    test_bsp(d, e, f, Point(0, 0), "Point(0, 0) [Inside]", true);
    test_bsp(d, e, f, Point(0, -6), "Point(0, -6) [Outside]", false);
    test_bsp(d, e, f, Point(-5, -5), "Point(-5, -5) [Vertex]", false);
    test_bsp(d, e, f, Point(0, -5), "Point(0, -5) [Edge]", false);

    return 0;
}
