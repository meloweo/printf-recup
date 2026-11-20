#include <unistd.h>
#include <stdarg.h>



int is_in(char ch)
{
	if (ch == 'd' || ch == 's' || ch == 'c' || 
		ch == 'i' || ch == 'u' || ch == 'x' || ch == 'X')
		return (1);
	return (0);
}

int ft_hexa(unsigned int n)
{
	char *hexa;

	hexa = "0123456789abcdef";
	n = n / 16;
	n = n % 16;
	
}

void	ft_conv(char ch, ...)
{
	int count;
	va_list ap;

	count = 0;
	if (ch == 'd')
		count = ft_putnbr(va_arg(ap, int));
	else if (ch == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (ch == 'c')
		count = ft_putchar(va_arg(ap, char));
	else if (ch == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if (ch == 'u')
		count = ft_put_unsnbr(va_arg(ap, unsigned int));
	else if (ch == 'x')
		count = ft_hexa(va_arg(ap, unsigned int));
	else if (ch == 'X')
		count = ft_hexa_maj(va_arg(ap, unsigned int));
	return (count);
}

int ft_printf(const char *str, ...)
{
	int i;
	int count; 

    va_list ap;
	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1] == '\0')
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && !is_in(str[i + 1]))
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && is_in(str[i + 1]))
		{
			count += ft_conv(str[i + 1], ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return(count);
}