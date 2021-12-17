/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:55:20 by jremy             #+#    #+#             */
/*   Updated: 2021/12/10 11:28:11 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.type = '0';
	flags.minus = 0;
	flags.dot = 0;
	flags.ndot = 0;
	flags.blank = 0;
	flags.hash = 0;
	flags.zero = 0;
	flags.plus = 0;
	flags.widht = 0;
	flags.negatif = 0;
	flags.value = 0;
	flags.nullbit = 0;
	flags.content = NULL;
	return (flags);
}

int	ft_parsing(char *src, va_list args)
{
	t_flags	flags;
	int		i;
	int		prtc;

	i = 1;
	prtc = 0;
	flags = ft_init_flags();
	if (ft_is_flag(src[i]))
		i = ft_parsing_flags(src + i, &flags);
	if (ft_valide_type(src[i]))
		i = ft_parsing_type(src[i], &flags, args);
	if (!flags.content)
		return (0);
	if (i > 0)
		prtc = ft_print(&flags);
	if (flags.content)
		free(flags.content);
	if (prtc == -1)
		return (0);
	return (prtc);
}

int	ft_treat(char *src, va_list args)
{
	int	i;
	int	prtc;

	i = 0;
	prtc = 0;
	while (src[i])
	{
		if (src[i] == '%' && src[i + 1])
		{
			if (ft_valide_type(src[i + 1]) || ft_is_flag(src[i + 1]))
			{
				prtc += ft_parsing(src + i, args);
			}
			i += ft_next_i(src + i + 1);
		}
		else
		{
			ft_putchar(src[i]);
			i++;
			prtc++;
		}
	}
	return (prtc);
}

int	ft_printf(const char *str, ...)
{
	char	*memory;
	va_list	args;
	int		return_value;

	memory = ft_strdup(str);
	va_start(args, str);
	return_value = 0;
	return_value += ft_treat(memory, args);
	va_end(args);
	free(memory);
	return (return_value);
}
