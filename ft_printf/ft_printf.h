/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-zant <hel-zant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:39:19 by hel-zant          #+#    #+#             */
/*   Updated: 2024/07/18 17:43:45 by hel-zant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PTRNULL "(nil)"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putlnbr(int nb);
int	ft_putlchr(char c);
int	ft_putlstr(char const *s);
int	ft_putlunbr(unsigned int nbr);
int	ft_putlhex(unsigned int num, const char c);
int	ft_putlptr(void *format);

#endif
