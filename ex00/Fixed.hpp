/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:25:13 by michel_32         #+#    #+#             */
/*   Updated: 2026/02/02 16:28:02 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
    int _value;
    static const int _bits = 8;
public:
    Fixed();
    Fixed(const Fixed &num);
    Fixed &operator=(const Fixed &num);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};


#endif