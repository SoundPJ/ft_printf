/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:48:55 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/26 01:53:22 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


//For put pointer
int	ft_putp(size_t n)
{
	int		len;

	len = 0;
	ft_putstr("0x");

	len = 2 + ft_putlu(n, 16, LOWER);
	return (len);
}