// header

#include "ft_printf.h"

static int	format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putuns(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
    int     check;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
        {
            check = format(*(++str), &args);
            if (check == -1)
                return (-1);
            len += check;
        }
        else
        {
            if (write(1, str, 1) == -1)
                return (va_end(args), -1);
			len++;
        }
        str++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int ft_len;
    int real_len;

	//basic strings
    ft_len = ft_printf("Hello world\n");
    real_len = printf("Hello world\n");
    printf("ft: %d | real: %d\n\n", ft_len, real_len);

	//putchar
    ft_len = ft_printf("Char: %c %c %c\n", 'A', '0', 127);
    real_len = printf("Char: %c %c %c\n", 'A', '0', 127);
    printf("ft: %d | real: %d\n\n", ft_len, real_len);

    //strings
    ft_len = ft_printf("String: %s | %s | %s\n", "hello", "", (char *)NULL);
    real_len = printf("String: %s | %s | %s\n", "hello", "", (char *)NULL);
    printf("ft: %d | real: %d\n\n", ft_len, real_len);

    //putnbr
    ft_len = ft_printf("Int: %d %i %d %i\n", 42, -42, INT_MAX, INT_MIN);
    real_len = printf("Int: %d %i %d %i\n", 42, -42, INT_MAX, INT_MIN);
    printf("ft: %d | real: %d\n\n", ft_len, real_len);

    //unsigned_putnbr
    ft_len = ft_printf("Unsigned: %u %u %u\n", 0, UINT_MAX, 123456789);
    real_len = printf("Unsigned: %u %u %u\n", 0, UINT_MAX, 123456789);
    printf("ft: %d | real: %d\n\n", ft_len, real_len);

    //hex
    ft_len = ft_printf("Hex x: %x %x %x\n", 0, 255, 4096);
    real_len = printf("Hex x: %x %x %x\n", 0, 255, 4096);
    printf("ft: %d | real: %d\n\n", ft_len, real_len);

    ft_len = ft_printf("Hex X: %X %X %X\n", 0, 255, 4096);
    real_len = printf("Hex X: %X %X %X\n", 0, 255, 4096);
    printf("ft: %d | real: %d\n\n", ft_len, real_len);

    //ptr
    int a = 42;
    char *str = "test";
    ft_len = ft_printf("Ptr: %p %p %p %p\n", &a, str, NULL, (void *)0);
    real_len = printf("Ptr: %p %p %p %p\n", &a, str, NULL, (void *)0);
    printf("ft: %d | real: %d\n\n", ft_len, real_len);

    //percentage
    ft_len = ft_printf("%% %% %% %%\n");
    real_len = printf("%% %% %% %%\n");
    printf("ft: %d | real: %d\n\n", ft_len, real_len);

    //mixed
    ft_len = ft_printf("Mix: %s %d %x %p %% %c\n",
                        "abc", -123, 255, &a, 'Z');
    real_len = printf("Mix: %s %d %x %p %% %c\n",
                      "abc", -123, 255, &a, 'Z');
    printf("ft: %d | real: %d\n\n", ft_len, real_len);

    //-1
    ft_len = ft_printf("%");
    printf("ft: %d (undefined behavior case)\n", ft_len);

    return 0;
}
*/