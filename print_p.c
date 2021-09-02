/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee <slee@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:04:39 by slee              #+#    #+#             */
/*   Updated: 2021/09/02 17:54:58 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_change_hex(unsigned long long n, char *base, int *length)
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

void	ft_putaddress(unsigned long long n, int *length)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, "0x", 2);
	(*length) += 2;
	ft_change_hex(n, base, length);
	return ;
}
