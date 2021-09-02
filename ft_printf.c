/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee <slee@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:22:15 by slee              #+#    #+#             */
/*   Updated: 2021/09/02 18:37:35 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(va_list ap, const char *format)
{
	int	length;

	length = 0;
	if (*format == 'c')
		length = ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		length = ft_putstr(va_arg(ap, char *));
	else if (*format == 'p')
		ft_putaddress(va_arg(ap, unsigned long long), &length);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(ap, int), &length);
	else if (*format == 'u')
		ft_putunsigned(va_arg(ap, unsigned int), &length);
	else if (*format == 'x' || *format == 'X')
		ft_puthex(va_arg(ap, unsigned int), &length, *format);
	else if (*format == '%')
		length = write(1, "%", 1);
	return (length);
}

int	read_format(va_list ap, const char *format)
{
	int	length;

	length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			length += print_type(ap, format);
		}
		else if (*format)
		{
			length += ft_putchar(*format);
		}
		format++;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		length;
	va_list	ap;

	va_start(ap, format);
	length = read_format(ap, format);
	va_end(ap);
	return (length);
}
