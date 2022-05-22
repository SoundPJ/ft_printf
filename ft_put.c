/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:02:43 by pjerddee          #+#    #+#             */
/*   Updated: 2022/05/22 12:32:31 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x(long n, int base, int ul)
{
	char	*num[2];
	long	tmp;
	int		len;

	tmp = n;
	// len = ft_getdigit(tmp, base);
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
		ft_putnbr_x(n / base, base, ul);
		write(1, num[ul] + (n % base), 1);
	}
	return (len);
}

// int	main(void)
// {
// 	ft_putnbr_x(255, 16, UPPER);
// 	ft_putnbr_x(255, 16, LOWER);
// 	ft_putnbr_x(255, 10, UPPER);
// 	printf("hi");
	
// 	return (0);
// }