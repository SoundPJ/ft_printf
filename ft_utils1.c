/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:44:27 by pjerddee          #+#    #+#             */
/*   Updated: 2022/05/23 03:10:36 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char *s, char c)
{
	int		i;

	i = 0;
	while(s[i] != '\0')
	{
		if (c == s[i])
			return 1;
		i++;
	}
	return 0;
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while(s[len] != '\0')
		len++;
	return (len);
}

void	t_cv_init(t_cv *spcf)
{
	spcf->type = '\0';
	spcf->flag1 = '\0';
	spcf->flag2 = '\0';
	spcf->sharp = 0;
	spcf->width = 0;
	spcf->precision = 0;
	spcf->len = 0;
}

// int main()
// {
// 	t_cv ret;

// 	t_cv_init(&ret);
// 	printf("type = %c\tflag1 = %c\tflag2 = %c\twidth = %d\tprecision = %d\tlen = %d\n", ret.type, ret.flag1, ret.flag2, ret.width, ret.precision, ret.len);
// 	return (0);
// }