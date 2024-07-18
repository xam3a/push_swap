/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-zant <hel-zant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:56:13 by hel-zant          #+#    #+#             */
/*   Updated: 2024/06/10 16:21:55 by hel-zant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char dest[20] = "Hello ";
// char src[] = "World";

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;
	size_t	j;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (s_len + size);
	i = d_len;
	j = 0;
	while (src[j] && (i + j) < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (d_len + s_len);
}
