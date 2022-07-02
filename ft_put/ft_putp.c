/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:48:55 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/02 15:24:56 by pjerddee         ###   ########.fr       */
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

static int	ft_putlu(size_t n, int base)
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

void	ft_putp(t_cv *spcf, size_t n)
{
	ft_putstr(spcf, "0x");
	spcf->len += ft_putlu(n, 16);
	// return (len);
}
