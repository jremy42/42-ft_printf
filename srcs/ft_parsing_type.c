/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:07:25 by jremy             #+#    #+#             */
/*   Updated: 2021/12/03 19:02:08 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_return_char(int c, t_flags *flags)
{
	char	*ret;

	if (c == 0)
	{
		ret = ft_calloc(2, sizeof(char));
		ret[0] = '$';
		ret[1] = '\0';
		flags->nullbit = 1;
		flags->content = ft_strdup(ret);
		free(ret);
	}
	else
	{
		ret = ft_calloc(2, sizeof(char));
		ret[0] = c;
		ret[1] = '\0';
		flags->content = ft_strdup(ret);
		free(ret);
	}
	flags->type = 'c';
}

void	ft_return_string(char *str, t_flags *flags)
{
	flags->type = 's';
	if (!str)
	{
		flags->content = ft_strdup("(null)");
		return ;
	}
	if (flags->blank)
		flags->blank = 0;
	flags->content = ft_strdup(str);
}

void	ft_return_int(int d, t_flags *flags)
{
	flags->type = 'd';
	if (d < 0)
	{
		d *= -1;
		flags->negatif = 1;
		flags->plus = 0;
		if (d == -2147483648)
		{
			flags->content = ft_strdup("2147483648");
			return ;
		}
	}
	if (d == 0 && flags->dot)
	{
		flags->content = ft_strdup("");
		return ;
	}
	flags->content = ft_itoa(d);
}

void	ft_return_point(void *p, t_flags *flags)
{
	unsigned long long	adrr;
	char				*tmp;

	adrr = (unsigned long long)p;
	tmp = ft_str_convert(adrr, "0123456789abcdef");
	flags->content = ft_strjoin("0x", tmp);
	flags->type = 'p';
	free(tmp);
}

int	ft_parsing_type(char type, t_flags *flags, va_list args)
{
	if (type == 'c')
		ft_return_char(va_arg(args, int), flags);
	if (type == 's')
		ft_return_string(va_arg(args, char *), flags);
	if (type == 'd' || type == 'i')
		ft_return_int(va_arg(args, int), flags);
	if (type == 'p')
		ft_return_point(va_arg(args, void *), flags);
	if (type == 'x' || type == 'X')
		ft_return_hexa(va_arg(args, unsigned int), flags, type);
	if (type == 'u')
		ft_return_u_int(va_arg(args, unsigned int), flags);
	if (type == '%')
		ft_return_percent(flags);
	return (1);
}
