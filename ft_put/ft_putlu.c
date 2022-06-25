/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:52:22 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/26 02:31:32 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// return number of digits of n, ignoring minus sign
static int	ft_getdigit(size_t n, int base)
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

int	ft_putlu(size_t n, int base, int ul)
{
	char	*num[2];
	long	tmp;
	int		len;

	tmp = n;
	len = ft_getdigit(tmp, base);
	num[LOWER] = "0123456789abcdef";
	num[UPPER] = "0123456789ABCDEF";
	if (n < base)
		write(1, num[ul] + (n % base), 1);
	else
	{
		ft_putlu(n / base, base, ul);
		write(1, num[ul] + (n % base), 1);
	}
	return (len);
}