/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:39:14 by jremy             #+#    #+#             */
/*   Updated: 2021/12/06 11:30:42 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_go_to_print_null(char *str)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		if (str[i] == '$')
			str[i] = '\0';
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_go_to_print(char *str, int nullbit)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	if (nullbit == 1)
	{
		i = ft_go_to_print_null(str);
		return (i);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_custom_join(char *add, t_flags *flags)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin(add, flags->content);
	if (!tmp)
		return (-1);
	free(flags->content);
	flags->content = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int	ft_treat_hash(t_flags *flags)
{
	int	ctrl_m;

	ctrl_m = 0;
	if (flags->type == 'x')
		ctrl_m = ft_custom_join("0x", flags);
	else
		ctrl_m = ft_custom_join("0X", flags);
	return (ctrl_m);
}

int	ft_print(t_flags *flags)
{
	int	mfw;
	int	ctrl_m;

	ctrl_m = 0;
	if (flags->dot == 1)
		ctrl_m = ft_treat_dot(flags);
	if (flags->plus == 1 && !flags->negatif && ctrl_m >= 0)
		ctrl_m = ft_custom_join("+", flags);
	if (flags->blank == 1 && !flags->negatif && !flags->plus && ctrl_m >= 0)
		ctrl_m = ft_custom_join(" ", flags);
	mfw = ft_mfw_size(flags);
	if (mfw > 0 && flags->zero && ctrl_m >= 0)
		ctrl_m = ft_treat_zero(mfw, flags);
	if (flags->hash == 1 && ctrl_m >= 0)
		ctrl_m = ft_treat_hash(flags);
	if (flags->negatif == 1 && ctrl_m >= 0)
		ctrl_m = ft_custom_join("-", flags);
	if (mfw > 0 && !flags->minus && !flags->zero && ctrl_m >= 0)
		ctrl_m = ft_treat_mfw(mfw, flags);
	if (mfw > 0 && flags->minus && !flags->zero && ctrl_m >= 0)
		ctrl_m = ft_treat_mfwr(mfw, flags);
	if (ctrl_m < 0)
		return (-1);
	ctrl_m = ft_go_to_print(flags->content, flags->nullbit);
	return (ctrl_m);
}
