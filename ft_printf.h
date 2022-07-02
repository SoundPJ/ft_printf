/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:31:30 by pjerddee          #+#    #+#             */
/*   Updated: 2022/07/03 05:58:51 by pjerddee         ###   ########.fr       */
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
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	ft_putstr(t_cv *spcf, char *s);
void	ft_putp(t_cv *spcf, size_t n);
void	ft_putnbr(t_cv *spcf, long n, int base, int ul);
void	ft_putpercent(t_cv *spcf);
void	ft_putchar(t_cv *spcf, char c);
int		ft_getlen(long n, int base);
void	t_cv_init(t_cv *spcf);

#endif
