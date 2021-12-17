/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:25:00 by jremy             #+#    #+#             */
/*   Updated: 2021/12/09 08:55:56 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treatdigit(char *str, int i, t_flags *flags)
{
	flags->widht = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	return (i - 1);
}

int	ft_flag_dot(char *str, int i, t_flags *flags)
{
	i++;
	flags->dot = 1;
	if (!ft_isdigit(str[i]))
	{
		flags->ndot = 0;
		return (i);
	}
	else
	{
		flags->ndot = ft_atoi(str + i);
		while (ft_isdigit(str[i]) && str[i])
			i++;
		return (i);
	}
}

int	ft_flag_minus(char *str, int i, t_flags *flags)
{
	i++;
	flags->minus = 1;
	while (str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (i);
	else
	{
		flags->widht = ft_atoi(str + i);
		while (ft_isdigit(str[i]) && str[i])
			i++;
		return (i);
	}
}

int	ft_flag_zero(char *str, int i, t_flags *flags)
{
	i++;
	flags->zero = 1;
	while (str[i] == '0')
		i++;
	if (!ft_isdigit(str[i]))
	{
		flags->zero = 0;
		return (i);
	}
	else
	{
		flags->widht = ft_atoi(str + i);
		while (ft_isdigit(str[i]) && str[i])
			i++;
		return (i);
	}
}

int	ft_parsing_flags(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_flag(str[i]))
	{	
		if (str[i] == ' ')
			flags->blank = 1;
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '0')
			i = ft_flag_zero(str, i, flags);
		if (str[i] == '-')
			i = ft_flag_minus(str, i, flags);
		if (str[i] == '.')
			i = ft_flag_dot(str, i, flags);
		if ((ft_isdigit(str[i])) && flags->dot == 0)
			i = ft_treatdigit(str, i, flags);
		if (ft_valide_type(str[i]) || str[i] == '%')
			break ;
		else
			i++;
	}
	return (ft_count_flags(str));
}
