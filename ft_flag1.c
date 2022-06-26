/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:38:24 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/26 08:22:33 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sharp(t_cv *spcf)
{
	if (spcf -> type == 'x')
		return (ft_putstr("0x"));
	else if (spcf -> type == 'X')
		return (ft_putstr("0X"));
	else
		return (0);
}

static int	ft_space(t_cv *spcf, long val)
{
	if (val >= 0)
		return (ft_putstr(" "));
	else
		return (0);
}

static int	ft_plus(t_cv *spcf, long val)
{
	if (val >= 0)
		return (ft_putstr("+"));
	else
		return (0);
}

int	ft_flag1()
{
	char	*tplus;
	char	*tspace;
	char	*tsharp;

	tplus = "di";
	tspace = "dixX";
	tsharp = "xX";
	if (spcf->flag1 == '+' && ft_check(tplus, spcf->type))
		ft_plus(spcf,);
	else if (spcf->flag1 == ' ' && ft_check(tspace, spcf->type))
		ft_space();
	else if (spcf->flag1 == '#' && ft_check(tsharp, spcf->type))
		ft_sharp();
}
