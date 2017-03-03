/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:52:26 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/10 00:53:54 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int i;
	int nb;
	int is_new_word;

	i = 0;
	nb = 0;
	is_new_word = 0;
	while (s[i])
	{
		if (is_new_word == 0 && s[i] != c)
		{
			is_new_word = 1;
			nb++;
		}
		if (s[i] == c)
		{
			is_new_word = 0;
		}
		i++;
	}
	return (nb);
}

static char		*next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char*)s);
}

static int		len_word(char const *s, char c)
{
	int len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**splitted;
	int		nb;
	int		i;

	if (!s)
		return (NULL);
	s = next_word(s, c);
	nb = word_count(s, c);
	if (!(splitted = malloc(sizeof(char*) * nb + 1)))
		return (NULL);
	i = 0;
	while (i < nb)
	{
		if (!(splitted[i] = (char *)malloc(sizeof(char) * len_word(s, c) + 1)))
			return (0);
		splitted[i] = ft_memcpy(splitted[i], s, len_word(s, c));
		splitted[i][len_word(s, c)] = '\0';
		s = s + len_word(s, c);
		s = next_word(s, c);
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}
