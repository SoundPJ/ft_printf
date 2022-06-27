/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:48:55 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/27 09:06:45 by pjerddee         ###   ########.fr       */
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

int	ft_putp(size_t n)
{
	int	len;

	len = 0;
	ft_putstr("0x");
	len = 2 + ft_putlu(n, 16);
	return (len);
}
