/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:48:11 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/03 05:20:07 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void ft_width(t_cv *spcf, char *s)
{
	int	l;

	l = ft_min(ft_strlen(s), spcf->precision);
	while (spcf->width-- > l)
		spcf->len += write(1, " ", 1);
	spcf->width = 0;
}

void	ft_putstr(t_cv *spcf, char *s)
{
	ft_width(spcf, s);
	if (!s)
	{
		write(1, "(null)", 6);
		spcf->len += 6;
		return ;
	}
	while (*s != '\0' && spcf->precision)
	{
		write(1, s++, 1);
		spcf->len += 1;
		if (spcf->precision > 0)
			spcf->precision--;
	}
}
