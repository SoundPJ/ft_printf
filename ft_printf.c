/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:26:54 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/26 07:57:29 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Priority # > + > space
static char	set_flag1(char o_flag1, char n_flag1)
{
	if (o_flag1 == '\0')
		return (n_flag1);
	if (o_flag1 == '#' || n_flag1 == '#')
		return ('#');
	else if (o_flag1 == '+' || n_flag1 == '+')
		return ('+');
	else
		return (' ');
}

//Priority - > 0
static char	set_flag2(char o_flag2, char n_flag2)
{
	if (o_flag2 == '\0')
		return (n_flag2);
	if (o_flag2 == '-' || n_flag2 == '-')
		return ('-');
	else
		return ('0');
}

static void	get_spcf(const char **s, t_cv *ret)
{
	int		dot;

	t_cv_init(ret);
	dot = 0;
	while (!ft_check(CONVERSION, **s))
	{
		if (ft_check(FLAG1, **s) && ret->width == 0 && ret->precision == 0)
			ret->flag1 = set_flag1(ret->flag1, **s);
		else if (ft_check(".", **s))
			dot = 1;
		else if (ft_check("#", **s))
			ret->flag1 = '#';
		else if (ft_check(FLAG2, **s) && dot == 0 && ret->width == 0)
			ret->flag2 = set_flag2(ret->flag2, **s);
		else if (ft_check(DIGIT, **s) && dot == 0)
			ret->width = (ret->width * 10) + (**s - '0');
		else if (ft_check(DIGIT, **s))
			ret->precision = (ret->precision * 10) + (**s - '0');
		(*s)++;
	}
	ret->type = **s;
}

// return printed len for a flag that parse in
static int	ft_classify(t_cv *spcf, va_list args)
{
	if (spcf->type == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (spcf->type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (spcf->type == 'p')
		return (ft_putp(va_arg(args, size_t)));
	else if (spcf->type == 'd' || spcf->type == 'i')
		return (ft_putnbr(va_arg(args, int), 10, LOWER));
	else if (spcf->type == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 10, LOWER));
	else if (spcf->type == 'x')
		return (ft_putnbr(va_arg(args, unsigned int), 16, LOWER));
	else if (spcf->type == 'X')
		return (ft_putnbr(va_arg(args, unsigned int), 16, UPPER));
	else if (spcf->type == '%')
		return (ft_putpercent());
	else
		return (0);
}

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	t_cv	spcf;
	int		flag;

	va_start(args, placeholders);
	flag = 0;
	spcf.len = 0;
	while (*placeholders != '\0')
	{
		if (*placeholders == '%' && flag == 0)
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			get_spcf(&placeholders, &spcf);
			spcf.len += ft_classify(&spcf, args);
		}
		else if (flag == 0)
			spcf.len += write(1, placeholders, 1);
		placeholders++;
	}
	va_end(args);
	return (spcf.len);
}
