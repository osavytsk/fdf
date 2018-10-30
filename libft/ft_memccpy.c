/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:34:36 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:38:34 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*wdst;
	unsigned char	*wsrc;

	wdst = dst;
	wsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*wdst = *wsrc;
		if (*wsrc == (unsigned char)c)
			return (++wdst);
		++wdst;
		++wsrc;
		++i;
	}
	return (NULL);
}
