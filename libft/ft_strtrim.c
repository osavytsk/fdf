/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:35:49 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*cpys;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	cpys = (char *)s + end - 1;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s++;
		start++;
	}
	while ((*cpys == ' ' || *cpys == '\n' || *cpys == '\t') && cpys > s)
	{
		cpys--;
		end--;
	}
	if (end - start <= 0)
		return (ft_strnew(0));
	if ((res = ft_strnew(end - start)) != NULL)
		return (ft_strncpy(res, s, (end - start)));
	return (NULL);
}
