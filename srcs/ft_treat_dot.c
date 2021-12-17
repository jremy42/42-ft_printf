/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:21:54 by jremy             #+#    #+#             */
/*   Updated: 2021/12/06 11:20:16 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_zero(char *dst, char *src, int ndot)
{
	int	i;
	int	y;
	int	len;

	i = 0;
	y = 0;
	len = (int)ft_strlen(src);
	while (i < (ndot - len))
	{
		dst[i] = '0';
		i++;
	}
	while (src[y])
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	return (dst);
}

int	ft_treat_dot_int(t_flags *flags)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = malloc((flags->ndot + 1) * sizeof(char));
	if (!tmp)
		return (-1);
	tmp[flags->ndot] = '\0';
	tmp2 = flags->content;
	tmp = ft_add_zero(tmp, tmp2, flags->ndot);
	free(flags->content);
	flags->content = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int	ft_treat_dot_str(t_flags *flags)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = malloc((flags->ndot + 1) * sizeof(char));
	tmp[flags->ndot] = '\0';
	if (!tmp)
		return (-1);
	tmp2 = flags->content;
	tmp = ft_memcpy(tmp, tmp2, flags->ndot);
	free(flags->content);
	flags->content = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int	ft_treat_dot_zero(t_flags *flags)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = malloc(1 * sizeof(char));
	if (!tmp)
		return (-1);
	tmp[0] = 0;
	free(flags->content);
	flags->content = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int	ft_treat_dot(t_flags *flags)
{
	if (!flags->content)
		return (-1);
	if (flags->type != '%')
		flags->zero = 0;
	if (flags->type != 's')
	{
		if (flags->ndot > (int)ft_strlen(flags->content))
			if (ft_treat_dot_int(flags) == -1)
				return (-1);
	}
	else
	{
		if (flags->ndot == 0)
			if (ft_treat_dot_zero(flags) == -1)
				return (-1);
		if (flags->ndot < (int)ft_strlen(flags->content))
			if (ft_treat_dot_str(flags) == -1)
				return (-1);
	}
	return (1);
}
