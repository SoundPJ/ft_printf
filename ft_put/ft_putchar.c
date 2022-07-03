/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:47:36 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/03 16:57:38 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_width(t_cv *spcf)
{
	while (spcf->width-- > 1)
		spcf->len += write(1, " ", 1);
	spcf->width = 0;
}

void	ft_putchar(t_cv *spcf, char c)
{
	if (spcf->flag2 == '-')
	{
		spcf->len += write(1, &c, 1);
		ft_width(spcf);
		return ;
	}
	else
	{
		ft_width(spcf);
		spcf->len += write(1, &c, 1);
		return ;
	}
}
