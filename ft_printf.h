// header

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_putuns(unsigned int n);
int	ft_puthex(unsigned long n, int up);
int	ft_putptr(void *ptr);

#endif