/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-zant <hel-zant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:08:10 by hel-zant          #+#    #+#             */
/*   Updated: 2024/06/26 15:02:43 by hel-zant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	check_char(va_list args, const char c)
{
	void	*ptr;

	if (c == 'd' || c == 'i')
		return (ft_putlnbr(va_arg(args, int)));
	else if (c == 'c')
		return (ft_putlchr(va_arg(args, int)));
	else if (c == 's')
		return (ft_putlstr(va_arg(args, char *)));
	else if (c == 'u')
		return (ft_putlunbr(va_arg(args, unsigned int)));
	else if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			return (ft_putlptr(ptr));
		return (ft_putlstr("(nil)"));
	}
	else if (c == 'x' || c == 'X')
		return (ft_putlhex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_putlchr('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_length += check_char(args, format[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
