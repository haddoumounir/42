/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:21:51 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/09 15:33:49 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_sc(int valuer_sc, va_list s_c)
{
	int	counter_sc;

	counter_sc = 0;
	if (valuer_sc == 'c')
	{
		counter_sc += ft_putchar_c(va_arg(s_c, int));
	}
	else if (valuer_sc == 's')
	{
		counter_sc += ft_putstr_c(va_arg(s_c, char *));
	}
	return (counter_sc);
}

int	handle_xxp(int valuer, va_list(xxp))
{
	int		counter_xxp;
	void	*temp;

	counter_xxp = 0;
	if (valuer == 'X' || valuer == 'x')
		counter_xxp += dec_to_hex(va_arg(xxp, int), valuer);
	if (valuer == 'p')
	{
		temp = va_arg(xxp, void *);
		if (temp == NULL)
			counter_xxp += ft_putstr_c("(nil)");
		else
		{
			counter_xxp += ft_putstr_c("0x");
			counter_xxp += dec_to_hex((unsigned long long)temp, 'p');
		}
	}
	return (counter_xxp);
}

int	handle_idu(int valuer_idu, va_list idu)
{
	int	counter_idu;

	counter_idu = 0;
	if (valuer_idu == 'd' || valuer_idu == 'i')
		counter_idu += ft_putnbr_c(va_arg(idu, int));
	else if (valuer_idu == 'u')
		counter_idu += ft_putunbr_c(va_arg(idu, unsigned int));
	return (counter_idu);
}

int	handle37(const char str, const char str1, va_list varb)
{
	int	counter;

	counter = 0;
	if (str1 == 'd' || str1 == 'u' || str1 == 'i')
		counter += handle_idu(str1, varb);
	else if (str1 == 'c' || str1 == 's')
		counter += handle_sc(str1, varb);
	else if (str1 == 'X' || str1 == 'x' || str1 == 'p')
		counter += handle_xxp(str1, varb);
	else if (str == '%' && str1 == '%')
		counter += ft_putchar_c(str1);
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	size_t	index;
	int		counter;

	if (!s)
		return (-1);
	va_list(varb);
	va_start(varb, s);
	counter = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == '%')
		{
			counter += handle37(s[index], s[index + 1], varb);
			index++;
		}
		else
			counter += ft_putchar_c(s[index]);
		index++;
	}
	va_end(varb);
	return (counter);
}
