/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-zant <hel-zant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:26:22 by hel-zant          #+#    #+#             */
/*   Updated: 2024/06/23 10:39:55 by hel-zant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_putlnbr(int nbr)
{
	char	*char_nbr;
	int		len;

	len = 0;
	char_nbr = ft_itoa(nbr);
	len = ft_strlen(char_nbr);
	write(1, char_nbr, len);
	free(char_nbr);
	return (len);
}
