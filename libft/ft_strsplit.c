/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:35:57 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cou_words(const char *str, char c)
{
	size_t col;
	size_t r;

	r = 0;
	col = 0;
	if (str[0] != c)
	{
		col++;
		r++;
	}
	while (str[r] != '\0')
	{
		if (str[r] != c && str[r - 1] == c)
			col++;
		r++;
	}
	return (col);
}

static char		*fill_words(const char *str, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	res = ft_strnew(i);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char		**errorro(char ***tab, size_t i)
{
	while (i > 0)
	{
		free(*tab[i]);
		i--;
	}
	free(*tab);
	return (NULL);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**res;
	size_t	cou_word;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	cou_word = cou_words(s, c);
	if (!(res = (char**)malloc((cou_word + 1) * sizeof(char*))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if ((res[i] = fill_words(s, c)) == NULL)
				return (errorro(&res, i - 1));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
