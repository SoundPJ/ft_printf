/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:26:54 by pjerddee          #+#    #+#             */
/*   Updated: 2022/05/22 14:14:08 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	t_cv	spcf;
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
			// spcf = ft_getcv(placeholders);
			flag = 0;
			len += spcf.len;
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
	printf("len: %d\n", ft_printf("Hello"));
	printf("len: %d\n", printf("Hello"));
	return (0);
}
