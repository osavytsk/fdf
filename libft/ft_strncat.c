/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:36:44 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, const char *src, int nb)
{
	int d;
	int s;

	s = 0;
	d = 0;
	while (dest[d] != '\0')
		d++;
	while (src[s] != '\0' && nb > 0)
	{
		dest[d] = src[s];
		d++;
		s++;
		nb--;
	}
	dest[d] = '\0';
	return (&dest[0]);
}
