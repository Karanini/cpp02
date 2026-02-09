/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:24:50 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/09 16:19:50 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int	main(void)
// {
// 	Fixed	a;
// 	Fixed	c;

// 	a.setRawBits(32);
// 	Fixed b(a);
// 	c = b;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;
// 	return (0);
// }

int	main(void)
{
	Fixed a;
	Fixed b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "--- Arithmetic tests ---" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "a + b is " << a + b << std::endl;
	std::cout << "a - b is " << a - b << std::endl;
	std::cout << "a * b is " << a * b << std::endl;
	std::cout << "b * a is " << b * a << std::endl;
	std::cout << "a / b is " << a / b << std::endl;

	std::cout << "--- Comparison tests ---" << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "b == d is " << (b == d) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl;

	return (0);
}
