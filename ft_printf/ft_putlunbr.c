/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-zant <hel-zant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:38:33 by hel-zant          #+#    #+#             */
/*   Updated: 2024/06/23 13:52:46 by hel-zant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static int	count_n(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = count_n(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

static int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putlunbr(unsigned int nbr)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (nbr == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(nbr);
		print_length += ft_printstr(num);
		free(num);
	}
	return (print_length);
}
