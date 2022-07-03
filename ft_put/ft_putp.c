/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:48:55 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/03 17:07:38 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_len(size_t n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

static int	ft_putlu(size_t n, size_t base)
{
	char	*num;
	long	tmp;
	int		len;

	tmp = n;
	len = ft_len(tmp, base);
	num = "0123456789abcdef";
	if (n < base)
		write(1, num + (n % base), 1);
	else
	{
		ft_putlu(n / base, base);
		write(1, num + (n % base), 1);
	}
	return (len);
}

static void	ft_width(t_cv *spcf, size_t n)
{
	int	l;

	l = ft_len(n, 16) + 2;
	while (spcf->width-- > l)
		spcf->len += write(1, " ", 1);
	spcf->width = 0;
}

void	ft_putp(t_cv *spcf, size_t n)
{
	if (spcf->flag2 == '-')
	{
		spcf->len += write(1, "0x", 2);
		spcf->len += ft_putlu(n, 16);
		ft_width(spcf, n);
		return ;
	}
	else
	{
		ft_width(spcf, n);
		spcf->len += write(1, "0x", 2);
		spcf->len += ft_putlu(n, 16);
		return ;
	}
}
