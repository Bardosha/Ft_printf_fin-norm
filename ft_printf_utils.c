/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veres <veres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:02:36 by asaunina          #+#    #+#             */
/*   Updated: 2026/07/15 01:14:55 by veres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	while (*s)
	{
		if (write(1, s, 1) == -1)
			return (-1);
		len++;
		s++;
	}
	return (len);
}