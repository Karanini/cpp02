/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:25:13 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/09 16:18:32 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
  private:
	int _value;
	static const int _fractional_bits = 8;

  public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &num);
	Fixed   &operator=(const Fixed &num);
	bool operator>(const Fixed &num) const;
	bool operator<(const Fixed &num) const;
	bool operator>=(const Fixed &num) const;
	bool operator<=(const Fixed &num) const;
	bool operator==(const Fixed &num) const;
	bool operator!=(const Fixed &num) const;
	Fixed operator+(const Fixed &num);
	Fixed operator-(const Fixed &num);
	Fixed operator*(const Fixed &num) const;
	Fixed operator/(const Fixed &num) const;
	Fixed	&operator++();
	Fixed	&operator++(int);
	Fixed	&operator--();
	Fixed	&operator--(int);
	~Fixed();
	int     getRawBits(void) const;
	void    setRawBits(int const raw);
	float   toFloat(void) const;
	int     toInt(void) const;
	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &output, Fixed const &i);

#endif
