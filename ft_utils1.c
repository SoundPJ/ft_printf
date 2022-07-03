/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:44:27 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/03 18:22:16 by pjerddee         ###   ########.fr       */
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

int	ft_getlen(long n, int base)
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

// return minimum, but if the minimum is negative return the other one
int	ft_min(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
	else if (a < 0 && b >= 0)
		return (b);
	else
		return (a);
}
