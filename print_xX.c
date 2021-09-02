/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee <slee@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:10:10 by slee              #+#    #+#             */
/*   Updated: 2021/09/02 12:09:28 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_change_hex(unsigned int n, char *base, int *length)
{
	if (n < 16)
	{
		ft_putchar(base[n % 16]);
		(*length)++;
		return ;
	}
	else
	{
		ft_change_hex(n / 16, base, length);
		ft_putchar(base[n % 16]);
		(*length)++;
	}
}

void	ft_puthex(unsigned int n, int *length, char format)
{
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (format == 'x')
		ft_change_hex(n, lower, length);
	else if (format == 'X')
		ft_change_hex(n, upper, length);
	return ;
}
