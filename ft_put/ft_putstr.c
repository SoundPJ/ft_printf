/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:48:11 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/04 03:47:44 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// return minimum, but if the minimum is negative return the other one
static int	ft_min(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
	else if (a < 0 && b >= 0)
		return (b);
	else
		return (a);
}

static void	ft_width(t_cv *spcf, char *s)
{
	int	l;

	l = ft_min(ft_strlen(s), spcf->precision);
	while (spcf->width-- > l)
		spcf->len += write(1, " ", 1);
	spcf->width = 0;
}

static void	ft_puts(t_cv *spcf, char *s)
{
	int	pcs;

	pcs = spcf->precision;
	if (!s)
	{
		s = "(null)";
		ft_putstr(spcf, s);
		return ;
	}
	while (*s != '\0' && pcs)
	{
		write(1, s++, 1);
		spcf->len += 1;
		if (pcs >= 0)
			pcs--;
	}
}

void	ft_putstr(t_cv *spcf, char *s)
{
	if (spcf->flag2 == '-')
	{
		ft_puts(spcf, s);
		ft_width(spcf, s);
		return ;
	}
	else
	{
		ft_width(spcf, s);
		ft_puts(spcf, s);
		return ;
	}
}
