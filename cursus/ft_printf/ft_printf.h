/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:22:34 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/09 23:46:10 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	handle37(const char str, const char str1, va_list varb);
int	handle_idu(int valuer_idu, va_list idu);
int	handle_xxp(int valuer, va_list(xxp));
int	handle_sc(int valuer_sc, va_list s_c);
int	ft_putchar_c(int c);
int	ft_putstr_c(char *s);
int	ft_putnbr_c(int nb);
int	dec_to_hex(unsigned long long n, char c);
int	ft_putunbr_c(unsigned int nb);
#endif