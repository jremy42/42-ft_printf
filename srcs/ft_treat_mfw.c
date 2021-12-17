/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_mfw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:54:12 by jremy             #+#    #+#             */
/*   Updated: 2021/12/03 18:51:33 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addchar(char *src, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		src[i] = value;
		i++;
	}
	src[i] = '\0';
	return (i);
}

int	ft_treat_mfw(int mfw, t_flags *flags)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = malloc((mfw + 1) * sizeof(char));
	if (!tmp)
		return (-1);
	tmp[mfw] = '\0';
	ft_addchar(tmp, ' ', mfw);
	tmp2 = flags->content;
	flags->content = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(tmp);
	return (1);
}

int	ft_treat_mfwr(int mfw, t_flags *flags)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = malloc((mfw + 1) * sizeof(char));
	if (!tmp)
		return (-1);
	tmp[mfw] = '\0';
	ft_addchar(tmp, ' ', mfw);
	tmp2 = flags->content;
	flags->content = ft_strjoin(tmp2, tmp);
	free(tmp2);
	free(tmp);
	return (1);
}
