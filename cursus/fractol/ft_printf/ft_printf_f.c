/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:38:30 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/09 15:34:41 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_c(char *s)
{
	size_t	index;

	index = 0;
	if (s == NULL)
		s = "(null)";
	while (s[index] != '\0')
		write(1, &s[index++], 1);
	return (index);
}

int	ft_putnbr_c(int nb)
{
	int	counter;

	counter = 0;
	if (nb == -2147483648)
		return (counter += ft_putstr_c("-2147483648"));
	else if (nb < 0)
	{
		counter += ft_putchar_c('-');
		counter += ft_putnbr_c(-nb);
	}
	else if (nb > 9)
	{
		counter += ft_putnbr_c(nb / 10);
		counter += ft_putnbr_c(nb % 10);
	}
	else
		counter += ft_putchar_c(48 + nb);
	return (counter);
}

int	dec_to_hex(unsigned long long n, char c)
{
	int		counter;
	size_t	rem;

	counter = 0;
	rem = 0;
	if (c == 'x' || c == 'X')
		n = (unsigned int)n;
	if (n == 0)
		return (counter += ft_putchar_c('0'), counter);
	if (n >= 16)
		counter += dec_to_hex(n / 16, c);
	rem = n % 16;
	if (rem < 10)
		counter += ft_putchar_c(rem + '0');
	else
		counter += ft_putchar_c(rem - 10 + c - (23 * (c == 'x' || c == 'X') + 15
					* (c == 'p')));
	return (counter);
}

int	ft_putunbr_c(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb > 9)
	{
		counter += ft_putunbr_c(nb / 10);
		counter += ft_putunbr_c(nb % 10);
	}
	else
		counter += ft_putchar_c(48 + nb);
	return (counter);
}
