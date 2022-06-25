/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:48:11 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/26 02:12:41 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//For putstr
int	ft_putstr(char *s)
{
	int	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return 6;
	}
	while (s[len] != '\0')
	{
		write(1, s + len, 1);
		len++;
	}
	return len;
}