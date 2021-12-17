/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:34:31 by jremy             #+#    #+#             */
/*   Updated: 2021/12/06 09:04:50 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_valide_type(char type)
{
	if (type == 'c' || type == 's' || type == 'p' || type == 'd' || type == 'i'
		|| type == 'u' || type == 'x' || type == 'X' || type == '%')
		return (1);
	else
		return (0);
}

int	ft_is_flag(char flag)
{
	if (flag == '.' || flag == ' ' || flag == '#' || flag == '0'
		|| flag == '-' || flag == '+' || ft_isdigit(flag))
		return (1);
	else
		return (0);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_return_percent(t_flags *flags)
{
	char	*ret;

	ret = ft_calloc(2, sizeof(char));
	if (!ret)
		return ;
	ret[0] = '%';
	ret[1] = '\0';
	flags->content = ft_strdup(ret);
	free(ret);
	flags->type = '%';
}

int	ft_next_i(char *src)
{
	int	i;

	i = 0;
	while (ft_is_flag(src[i]) && src[i])
		i++;
	if (ft_valide_type(src[i]) && src[i])
		i++;
	return (i + 1);
}
