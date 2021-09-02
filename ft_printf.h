/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee <slee@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:22:41 by slee              #+#    #+#             */
/*   Updated: 2021/09/02 17:55:23 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *arg, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
void	ft_putnbr(int n, int *length);
void	ft_putunsigned(unsigned int n, int *length);
void	ft_putaddress(unsigned long long n, int *length);
void	ft_puthex(unsigned int n, int *length, char format);

#endif
