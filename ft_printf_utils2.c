/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaunina <asaunina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:00:22 by asaunina          #+#    #+#             */
/*   Updated: 2026/07/15 17:29:26 by asaunina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int	len;
	int	check;

	len = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		n = -n;
	}
	if (n >= 10)
	{
		check = ft_putnbr(n / 10);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_putuns(unsigned int n)
{
	int	len;
	int	check;

	len = 0;
	if (n >= 10)
	{
		check = ft_putuns(n / 10);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_puthex(unsigned long n, int up)
{
	char	*base;
	int		len;
	int		check;

	len = 0;
	if (up)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		check = ft_puthex(n / 16, up);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	check;

	len = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	check = ft_putstr("0x");
	if (check == -1)
		return (-1);
	len += check;
	check = ft_puthex((unsigned long)ptr, 0);
	if (check == -1)
		return (-1);
	return (len + check);
}
