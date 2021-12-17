/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:47:47 by jremy             #+#    #+#             */
/*   Updated: 2021/11/24 10:33:18 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recu_fd(unsigned int sn, int fd)
{
	char	c;

	if (sn < 10)
	{
		c = sn + '0';
		ft_putchar_fd(c, fd);
		return ;
	}
	ft_putnbr_recu_fd(sn / 10, fd);
	c = sn % 10 + '0';
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	sn;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sn = n * -1;
	}
	else
		sn = n;
	ft_putnbr_recu_fd(sn, fd);
}
