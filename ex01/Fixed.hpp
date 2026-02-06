/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:25:13 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/06 14:06:08 by bkaras-g         ###   ########.fr       */
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
	~Fixed();
	int     getRawBits(void) const;
	void    setRawBits(int const raw);
	float   toFloat(void) const;
	int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &output, Fixed const &i);

#endif
