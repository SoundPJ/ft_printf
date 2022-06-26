/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:31:30 by pjerddee          #+#    #+#             */
/*   Updated: 2022/06/26 08:15:33 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# define LOWER 0
# define UPPER 1
# define FLAG1 "+ #"
# define FLAG2 "-0"
# define DIGIT "0123456789"
# define CONVERSION "cspdiuxX%"

typedef struct s_cv{
	char	type;
	char	flag1;
	char	flag2;
	int		width;
	int		precision;
	int		len;
}	t_cv;

int		ft_printf(const char *placeholders, ...);
int		ft_check(char *s, char c);
int		ft_strlen(char *s);
int		ft_putstr(char *s);
int		ft_putp(size_t n);
int		ft_putnbr(long n, int base, int ul);
int		ft_putlu(size_t n, int base, int ul);
int		ft_putpercent(void);
int		ft_putchar(char c);
void	t_cv_init(t_cv *spcf);

#endif
