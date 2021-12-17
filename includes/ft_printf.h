/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:43:59 by jremy             #+#    #+#             */
/*   Updated: 2021/12/10 11:28:10 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	char	type;
	int		minus;
	int		dot;
	int		ndot;
	int		blank;
	int		hash;
	int		zero;
	int		plus;
	int		widht;
	int		nullbit;
	int		negatif;
	size_t	value;
	char	*content;
}	t_flags;

int		ft_count_flags(char *str);
int		ft_mfw_size(t_flags *flags);
int		ft_is_flag(char flag);
int		ft_valide_type(char type);
int		ft_parsing_flags(char *src, t_flags *flags);
int		ft_printf(const char *str, ...);
void	ft_print_struct(t_flags flags);
void	ft_return_u_int(unsigned int d, t_flags *flags);
void	ft_return_hexa(unsigned int x, t_flags *flags, char type);
void	ft_return_u_int(unsigned int d, t_flags *flags);
void	ft_putchar(int c);
char	*ft_str_convert(unsigned long long nb, char *base_to);
int		ft_parsing_type(char type, t_flags *flags, va_list args);
int		ft_treat_dot(t_flags *flags);
int		ft_print(t_flags *flags);
int		ft_treat_mfw(int mfw, t_flags *flags);
int		ft_treat_mfwr(int mfw, t_flags *flags);
void	ft_return_percent(t_flags *flags);
int		ft_next_i(char *src);
int		ft_treat_zero(int mfw, t_flags *flags);
void	ft_putstr(char const *s);
#endif
