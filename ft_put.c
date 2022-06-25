/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:02:43 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/25 23:46:13 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

//For putchar and putstr
int	ft_putstr(char *s)
{
	int	len = 0;
	while (s[len] != '\0')
	{
		write(1, s + len, 1);
		len++;
	}
	return len;
}

//For put pointer
int	ft_putp(unsigned long n)
{
	int		len;

	len = 0;
	ft_putstr("0x");
	len = 2 + ft_putnbr((long)n, 16, LOWER);
	return (len);
}

int	ft_putnbr(long n, int base, int ul)
{
	char	*num[2];
	long	tmp;
	int		len;

	tmp = n;
	len = ft_getdigit(tmp, base);
	num[LOWER] = "0123456789abcdef";
	num[UPPER] = "0123456789ABCDEF";
	if (n < 0)
	{
		write (1, "-", 1);
		n = n * -1;
		len++;
	}
	if (n < base)
		write(1, num[ul] + (n % base), 1);
	else
	{
		ft_putnbr(n / base, base, ul);
		write(1, num[ul] + (n % base), 1);
	}
	return (len);
}

int	ft_putpercent()
{
	ft_putstr("%");
	return 1;
}
