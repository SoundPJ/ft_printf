/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:51:17 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/04 04:00:20 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_flag1(t_cv *spcf, long n, int base, int ul)
{
	if (n >= 0 && spcf->flag1 == '+' && !ft_check("uxX", spcf->type))
		spcf->len += write(1, "+", 1);
	if (n >= 0 && spcf->flag1 == ' ' && !ft_check("uxX", spcf->type))
		spcf->len += write(1, " ", 1);
	if (spcf->type == 'x' && spcf->flag1 == '#' && n != 0)
		spcf->len += write(1, "0x", 2);
	if (spcf->type == 'X' && spcf->flag1 == '#' && n != 0)
		spcf->len += write(1, "0X", 2);
	if (n == 0 && spcf->precision == 0)
		return ;
	if (!(spcf->precision >= 0 && n == 0))
		ft_putn(spcf, n, base, ul);
}

static int	ft_precision(t_cv *spcf, long n, int base)
{
	int	pad0;

	if (spcf->precision >= 0 && spcf->precision >= ft_getlen(n, base, spcf))
	{
		pad0 = spcf->precision - ft_getlen(n, base, spcf);
		if (n < 0 && spcf->precision >= 0)
			pad0++;
	}
	else
		pad0 = 0;
	return (pad0);
}

static void	ft_width(t_cv *spcf, long n, int base, int pad0)
{
	while (spcf->width-- > pad0 + ft_getlen(n, base, spcf))
	{
		if (spcf->flag2 == '0' && spcf->precision < 0)
			spcf->len += write(1, "0", 1);
		else
			spcf->len += write(1, " ", 1);
	}
}

static void	ft_minus(t_cv *spcf, long n, int base, int ul)
{
	int	pad0;
	int	i;

	pad0 = ft_precision(spcf, n, base);
	i = 0;
	if (spcf->flag2 == '-')
	{
		while (i++ < pad0)
			spcf->len += write(1, "0", 1);
		ft_flag1(spcf, n, base, ul);
		ft_width(spcf, n, base, pad0);
	}
	else
	{
		ft_width(spcf, n, base, pad0);
		if (n < 0 && spcf->flag2 == '0' && spcf->precision >= 0)
		{
			spcf->len += write (1, "-", 1);
			n *= -1;
		}
		while (i++ < pad0)
			spcf->len += write(1, "0", 1);
		ft_flag1(spcf, n, base, ul);
	}
}

void	ft_putnbr(t_cv *spcf, long n, int base, int ul)
{
	if (n < 0 && ((spcf->flag2 == '0') != (spcf->precision >= 0)))
	{
		n *= -1;
		spcf->len += write(1, "-", 1);
		spcf->width--;
	}
	ft_minus(spcf, n, base, ul);
}
