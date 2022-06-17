/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:26:54 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/18 00:00:33 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Priority # > + > space
static char	set_flag1(char o_flag1, char n_flag1)
{
	if (o_flag1 == '\0')
		return n_flag1;
	if (o_flag1 == '#' || n_flag1 == '#')
		return '#';
	else if (o_flag1 == '+' || n_flag1 == '+')
		return '+';
	else
		return ' ';
}


//Priority - > 0
static char	set_flag2(char o_flag2, char n_flag2)
{
	if (o_flag2 == '\0')
		return n_flag2;
	if (o_flag2 == '-' || n_flag2 == '-')
		return '-';
	else
		return '0';
}

t_cv	get_spcf(char *s)
{
	t_cv	ret;
	int		dot;

	t_cv_init(&ret);
	dot = 0;
	while (!ft_check(CONVERSION, *s))
	{
		if (ft_check(FLAG1, *s) && ret.width == 0 && ret.precision == 0)
			ret.flag1 = set_flag1(ret.flag1, *s);
		else if (ft_check(".", *s))
			dot = 1;
		else if (ft_check("#", *s))
			ret.flag1 = '#';
		else if (ft_check(FLAG2, *s) && dot == 0 && ret.width == 0)
			ret.flag2 = set_flag2(ret.flag2, *s);
		else if (ft_check(DIGIT, *s) && dot == 0)
			ret.width = (ret.width * 10) + (*s - '0');
		else if (ft_check(DIGIT, *s))
			ret.precision = (ret.precision * 10) + (*s - '0');
		s++;
	}
	ret.type = *s;
	printf("type = '%c' flag1 = '%c' flag2 = '%c' width = '%d' precision = '%d' len = '%d'\n", ret.type, ret.flag1, ret.flag2, ret.width, ret.precision, ret.len);
	return (ret);
}

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	int		len;
	int		flag;

	va_start(args, placeholders);
	len = 0;
	flag = 0;
	while (*placeholders != '\0')
	{
		if (*placeholders == '%' && flag == 0)
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			// len += ft_flag(placeholders);
		}
		else if (flag == 0)
			write(1, placeholders, 1);
		placeholders++;
		len++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	// get_spcf("+5d");
	// get_spcf("+-5d");
	// get_spcf("-+5d");
	// get_spcf("+0.4d");

	// get_spcf("- 6d");
	// get_spcf("0 6d");
	// get_spcf("- 7.4d");
	// get_spcf("- 5.4d");
	// get_spcf("0 .5d");

	// get_spcf("#04x");
	// get_spcf("-#4x");
	// get_spcf("#2.1x");

	// ft_putchar('c');
	// ft_putstr("Hello");
	// int a = 2;
	// printf("%p\n", &a);
	// ft_putp((unsigned long)&a);

	ft_printf("Hello");
	return (0);
}
