/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 04:09:58 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/04 04:10:02 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//check if char c in str s. If yes return 1, return 0 otherwise.
int	ft_check(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

//For example, "Hello" return 5
int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (6);
	while (s[len] != '\0')
		len++;
	return (len);
}

//Initialise cv
void	t_cv_init(t_cv *spcf)
{
	spcf->type = '\0';
	spcf->flag1 = '\0';
	spcf->flag2 = '\0';
	spcf->width = 0;
	spcf->precision = -1;
}

int	ft_getlen(long n, int base, t_cv *spcf)
{
	int	len;

	len = 0;
	if (n == 0 && spcf->precision < 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

void	ft_putn(t_cv *spcf, long n, int base, int ul)
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
