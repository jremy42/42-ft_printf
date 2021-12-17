/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:34:31 by jremy             #+#    #+#             */
/*   Updated: 2021/12/09 08:54:12 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_flags(char *str)
{
	int	i;

	i = 0;
	while (ft_is_flag(str[i]))
		i++;
	return (i + 1);
}

int	ft_mfw_size(t_flags *flags)
{
	int	mfw;

	mfw = 0;
	mfw = flags->widht - flags->negatif - flags->plus - flags->blank;
	mfw -= ft_strlen(flags->content);
	return (mfw);
}

void	ft_putstr(char const *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
