/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 09:41:35 by jremy             #+#    #+#             */
/*   Updated: 2021/12/03 18:55:04 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size(unsigned long long nb, int size_b)
{
	int					neg;
	int					i;
	unsigned long long	unb;

	unb = nb;
	neg = 0;
	i = 0;
	if (unb < 0)
	{
		unb *= -1;
		neg++;
	}
	if (unb == 0)
		return (1);
	while (unb > 0)
	{
		unb /= size_b;
		i++;
	}
	return ((int)(i + neg));
}

char	*ft_convert_new_b(unsigned long long lnb, char *str, char *b_to, int s)
{
	int	i;

	i = ft_strlen(b_to);
	while (lnb >= ft_strlen(b_to))
	{
		str[s] = b_to[lnb % i];
		lnb = lnb / i;
		s--;
	}
	str[s] = b_to[lnb % i];
	return (str);
}

char	*ft_str_convert(unsigned long long nb, char *base_to)
{
	int					size_str;
	int					size_b;
	char				*str;
	unsigned long long	lnb;

	size_b = ft_strlen(base_to);
	size_str = ft_size(nb, size_b);
	str = malloc(sizeof(char) * (size_str + 1));
	if (!(str))
		return (NULL);
	str[size_str] = 0;
	if (nb < 0)
	{
		str[0] = '-';
		lnb = nb;
		lnb *= -1;
	}
	else
		lnb = nb;
	str = ft_convert_new_b(lnb, str, base_to, size_str - 1);
	return (str);
}
