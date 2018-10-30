/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:37:10 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*retcpy;
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = (char *)s1;
	while (*cpy != '\0')
	{
		i++;
		cpy++;
	}
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	retcpy = ret;
	while (*s1 != '\0')
		*ret++ = *s1++;
	*ret = '\0';
	return (retcpy);
}
