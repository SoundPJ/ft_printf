/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:38:24 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/02 16:37:39 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sharp(t_cv *spcf)
{
	if (spcf -> type == 'x')
		ft_putstr(spcf, "0x");
	else if (spcf -> type == 'X')
		ft_putstr(spcf, "0X");
}

static void	ft_space(t_cv *spcf, long val)
{
	if (val >= 0)
		ft_putstr(spcf, " ");
}

static void	ft_plus(t_cv *spcf, long val)
{
	if (val >= 0)
		ft_putstr(spcf, "+");
}

int	ft_flag1(t_cv *spcf, long val)
{
	char	*tplus;
	char	*tspace;
	char	*tsharp;

	tplus = "di";
	tspace = "dixX";
	tsharp = "xX";
	if (spcf->flag1 == '+' && ft_check(tplus, spcf->type))
		ft_plus(spcf, val);
	else if ((spcf->flag1 == ' ' || spcf->flag1 == '\0')&& ft_check(tspace, spcf->type))
		ft_space(spcf, val);
	else if (spcf->flag1 == '#' && ft_check(tsharp, spcf->type))
		ft_sharp(spcf);
}
