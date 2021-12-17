/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:39:25 by jremy             #+#    #+#             */
/*   Updated: 2021/11/24 17:12:51 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freetab(char**tab, int index)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i <= index)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
	}
	free(tab);
	return (NULL);
}

static size_t	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	count_word;

	count_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count_word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count_word);
}

static char	*ft_getnextstr(const char *s, char c, size_t *len_nextstr)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != c && *s)
			{
				i++;
				s++;
			}
			*len_nextstr = i;
			return ((char *)s - i);
		}
		s++;
	}
	len_nextstr++;
	return ((char *)s + i);
}

static char	*ft_strncpy(char *dst, const char *src, size_t count)
{
	size_t	i;

	i = 0;
	while (src[i] && i < count)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < count)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	count_word;
	size_t	i;
	size_t	len_nextstr;

	i = 0;
	len_nextstr = 0;
	if (!s)
		return (NULL);
	count_word = ft_count_word(s, c);
	result = malloc(sizeof(char *) * (count_word + 1));
	if (!result)
		return (NULL);
	while (i < count_word)
	{
		s = ft_getnextstr(s + len_nextstr, c, &len_nextstr);
		result[i] = ft_calloc(len_nextstr + 1, sizeof(char));
		if (! result[i])
			return (ft_freetab(result, i));
		result[i] = ft_strncpy(result[i], s, len_nextstr);
		result[i][len_nextstr] = '\0';
		i++;
	}
	result[count_word] = NULL;
	return (result);
}
