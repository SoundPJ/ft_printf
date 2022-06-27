/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:44:27 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/27 08:53:01 by pjerddee         ###   ########.fr       */
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
	spcf->precision = 0;
}


