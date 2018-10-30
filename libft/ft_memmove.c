/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:38:17 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dstcpy;
	void	*srccpy;

	if (src < dst)
	{
		dstcpy = dst + len - 1;
		srccpy = (void *)src + len - 1;
		while (len > 0)
		{
			*(unsigned char *)dstcpy-- = *(unsigned char *)srccpy--;
			len--;
		}
	}
	else
	{
		dstcpy = dst;
		srccpy = (void *)src;
		while (len > 0)
		{
			*(unsigned char *)dstcpy++ = *(unsigned char *)srccpy++;
			len--;
		}
	}
	return (dst);
}
