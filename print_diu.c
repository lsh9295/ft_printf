/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee <slee@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:02:01 by slee              #+#    #+#             */
/*   Updated: 2021/09/02 18:39:23 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int n, int *length)
{
	char	i;

	if (n < 10)
	{
		i = n % 10 + '0';
		(*length)++;
		ft_putchar(i);
		return ;
	}
	else
	{
		ft_putunsigned(n / 10, length);
		i = n % 10 + '0';
		(*length)++;
		ft_putchar(i);
	}
}

void	ft_write_num(int n, int *length)
{
	char	i;

	if (n == 0)
		return ;
	i = n % 10 + '0';
	n = n / 10;
	(*length)++;
	ft_write_num(n, length);
	ft_putchar(i);
}

void	ft_putnbr(int n, int *length)
{
	if (n == -2147483648)
	{
		*length = ft_putstr("-2147483648");
		return ;
	}
	if (n == 0)
		*length = ft_putchar('0');
	else if (n > 0)
		ft_write_num(n, length);
	else if (n < 0)
	{
		*length = ft_putchar('-');
		n = -n;
		ft_write_num(n, length);
	}
	return ;
}
