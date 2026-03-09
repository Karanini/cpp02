/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:24:50 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/09 17:29:48 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "--- Basic tests ---" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "a as int: " << a.toInt() << std::endl;
	std::cout << "b as float: " << b.toFloat() << std::endl;

	std::cout << "\n--- Arithmetic tests ---" << std::endl;
	std::cout << "a + b is " << a + b << std::endl;
	std::cout << "a - b is " << a - b << std::endl;
	std::cout << "a * b is " << a * b << std::endl;
	std::cout << "a / b is " << a / b << std::endl;
	std::cout << "Division by zero: ";
	Fixed(1) / Fixed(0);

	std::cout << "\n--- Comparison tests ---" << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "b == d is " << (b == d) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl;

	std::cout << "\n--- Increment/Decrement tests ---" << std::endl;
	Fixed e;
	std::cout << "e initially: " << e << std::endl;
	std::cout << "++e: " << ++e << std::endl;
	std::cout << "e now: " << e << std::endl;
	std::cout << "++(++e): " << ++(++e) << std::endl;
	std::cout << "e now: " << e << std::endl;
	std::cout << "e++: " << e++ << std::endl;
	std::cout << "e now: " << e << std::endl;
	std::cout << "--e: " << --e << std::endl;
	std::cout << "e now: " << e << std::endl;
	std::cout << "--(--e): " << --(--e) << std::endl;
	std::cout << "e now: " << e << std::endl;
	std::cout << "e--: " << e-- << std::endl;
	std::cout << "e now: " << e << std::endl;

	std::cout << "\n--- Precision tests ---" << std::endl;
	Fixed f(0.00390625f); // 1/256 - smallest positive value
	Fixed g(0.001953125f); // 0.5/256 - should round
	std::cout << "1/256: " << f << std::endl;
	std::cout << "0.5/256: " << g << std::endl;
	std::cout << "f * 2: " << f * Fixed(2) << std::endl;

	std::cout << "\n--- Min/Max tests ---" << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "const min(c, d): " << Fixed::min(c, d) << std::endl;
	std::cout << "const max(c, d): " << Fixed::max(c, d) << std::endl;

	return (0);
}
