/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-zant <hel-zant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:37:59 by hel-zant          #+#    #+#             */
/*   Updated: 2024/06/23 16:18:12 by hel-zant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char c)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, c);
		ft_put_hex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (c == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_putlhex(unsigned int num, const char c)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, c);
	return (ft_hex_len(num));
}
