/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:31:30 by pjerddee          #+#    #+#             */
/*   Updated: 2022/05/22 10:06:22 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define	FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# define LOWER 0
# define UPPER 1
# define FLAG1 "# +"
# define FLAG2 "-0."

typedef struct s_cv{
	char	type;
	char	flag1;
	char	flag2;
	int		width;
	int		precision;
	int		len;
} t_cv;

int ft_printf(const char *, ...);

#endif
