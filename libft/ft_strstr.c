/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:35:54 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t n;

	n = ft_strlen((char *)s2);
	while (*s1)
	{
		if (!ft_memcmp(s1++, s2, n))
			return ((char *)s1 - 1);
	}
	if (*s2 == 0)
		return ((char *)s1);
	return (NULL);
}
