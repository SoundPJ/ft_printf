/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:38:24 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/22 23:22:24 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sharp(t_cv *spcf)
{
	if (spcf -> type == 'x')
		return ft_putstr("0x");
	else if (spcf -> type == 'X')
		return ft_putstr("0X");
}

int ft_space(t_cv *spcf, long val)
{
	if (val >= 0)
		return ft_putstr(" ");
}

int ft_plus(t_cv *spcf, long val)
{
	if (val >= 0)
		return ft_putstr("+");
}
