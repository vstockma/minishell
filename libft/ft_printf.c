/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:03:31 by vstockma          #+#    #+#             */
/*   Updated: 2022/11/17 13:12:27 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_type(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == '%')
		len = len + ft_putc('%');
	if (format == 'c')
		len = len + ft_putc(va_arg(args, int));
	if (format == 's')
		len = len + ft_puts(args);
	if (format == 'd' || format == 'i')
		len = len + ft_putdi(args);
	if (format == 'u')
		len = len + ft_putu(args);
	if (format == 'x')
		len = len + ft_putxlower(args);
	if (format == 'X')
		len = len + ft_putxupper(args);
	if (format == 'p')
		len = len + ft_putp(args);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = len + ft_type(args, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main()
{
	char		c = 100;
	int		i = 5; //2147483648
	unsigned int	u = 568888; //4294967295
	int		len;
	int		orglen;
	char		*str = "Hallo";

	ft_printf("Print %%\n");
	orglen = printf("Char OgPrintf: %%\n");
	len = ft_printf("Char MyPrintf: %%\n");
	printf("orglen: %d  len: %d\n\n", orglen, len);

	ft_printf("Print Char\n");
	orglen = printf("Char OgPrintf: %c\n", c);
	len = ft_printf("Char MyPrintf: %c\n", c);
	printf("orglen: %d  len: %d\n\n", orglen, len);

	ft_printf("Print String\n");
	orglen = printf("Str OgPrintf: %s\n", str);
	len = ft_printf("Str MyPrintf: %s\n", str);
	printf("orglen: %d  len: %d\n\n", orglen, len);
	
	ft_printf("Print Int\n");
	orglen = printf("Int OgPrintf: %i\n", i);
	len = ft_printf("Int MyPrintf: %i\n", i);
	printf("orglen: %d  len: %d\n\n", orglen, len);

	ft_printf("Print Unsigned Int\n");
	orglen = printf("Unsigned Int OgPrintf: %u\n", u);
	len = ft_printf("Unsigned Int MyPrintf: %u\n", u);
	printf("orglen: %d  len: %d\n\n", orglen, len);

	ft_printf("Print Hexlower\n");
	orglen = printf("Hexlower OgPrintf: %x\n", u);
	len = ft_printf("Hexlower MyPrintf: %x\n", u);
	printf("orglen: %d  len: %d\n\n", orglen, len);

	ft_printf("Print Hexuppper\n");
	orglen = printf("Hexupper OgPrintf: %X\n", u);
	len = ft_printf("Hexupper MyPrintf: %X\n", u);
	printf("orglen: %d  len: %d\n\n", orglen, len);

	ft_printf("Print Pointer\n");
	orglen = printf("Pointer OgPrintf: %p\n", str);
	len = ft_printf("Pointer MyPrintf: %p\n", str);
	printf("orglen: %d  len: %d\n\n", orglen, len);
}
*/
