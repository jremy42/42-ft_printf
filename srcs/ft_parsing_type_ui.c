/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_type_ui.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:44:24 by jremy             #+#    #+#             */
/*   Updated: 2021/12/03 19:02:37 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_u_intsize(unsigned int n)
{
	size_t		result;

	result = 0;
	while (n > 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

void	ft_u_itoa_recu(unsigned int sn, char *result, size_t start)
{
	if (sn < 10)
	{
		result[start] = sn + '0';
		return ;
	}
	ft_u_itoa_recu(sn / 10, result, start - 1);
	result[start] = sn % 10 + '0';
}

char	*ft_u_itoa(unsigned int n)
{
	char		*result;
	size_t		size;

	if (n == 0)
	{
		result = ft_calloc(2, sizeof(char));
		result[0] = '0';
		return (result);
	}
	size = ft_u_intsize(n);
	result = ft_calloc(size + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_u_itoa_recu(n, result, size - 1);
	return (result);
}

void	ft_return_u_int(unsigned int d, t_flags *flags)
{
	if (d == 0 && flags->dot)
	{
		flags->content = ft_strdup("");
		return ;
	}
	flags->content = ft_u_itoa(d);
	flags->type = 'u';
}
