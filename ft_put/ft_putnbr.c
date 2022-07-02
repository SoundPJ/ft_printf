/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:51:17 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/02 16:09:43 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr(t_cv *spcf, long n, int base, int ul)
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
		ft_putnbr(spcf, n / base, base, ul);
		spcf->len += write(1, num[ul] + (n % base), 1);
	}
}
