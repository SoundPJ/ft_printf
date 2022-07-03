/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:51:17 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/03 17:18:00 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putn(t_cv *spcf, long n, int base, int ul)
{
	char	*num[2];
	long	tmp;

	tmp = n;
	num[LOWER] = "0123456789abcdef";
	num[UPPER] = "0123456789ABCDEF";
	if (n < 0)
	{
		spcf->len += write (1, "-", 1);
		n = n * -1;
	}
	if (n < base)
		spcf->len += write(1, num[ul] + (n % base), 1);
	else
	{
		ft_putn(spcf, n / base, base, ul);
		spcf->len += write(1, num[ul] + (n % base), 1);
	}
}

static void	ft_width(t_cv *spcf, long n, int base, int n_zero)
{
	int	l;
	
	l = ft_getlen(n, base) + n_zero;
	if (spcf->flag1 != '\0' && n >= 0 && spcf->type != 'u')
		l++;
	while (spcf->width-- > l)
	{
		if (spcf->flag2 == '0')
			spcf->len += write(1, "0", 1);
		else
			spcf->len += write(1, " ", 1);
	}
	while (n_zero-- > 0)
		spcf->len += write(1, "0", 1);
	spcf->width = 0;
}

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
	ft_putn(spcf, n, base, ul);
}

void	ft_putnbr(t_cv *spcf, long n, int base, int ul)
{
	int	n_zero;

	n_zero = spcf->precision - ft_getlen(n, base);
	if (n_zero < 0)
		n_zero = 0;
	if (n < 0 && (spcf->flag2 == '0' || spcf->precision >= 0))
	{
		n *= -1;
		spcf->len += write(1, "-", 1);
		spcf->width--;
	}
	if (spcf->flag2 == '-')
	{
		ft_flag1(spcf, n, base, ul);
		ft_width(spcf, n, base, n_zero);
		return ;
	}
	else
	{
		ft_width(spcf, n, base, n_zero);
		ft_flag1(spcf, n, base, ul);
		return ;
	}
}
