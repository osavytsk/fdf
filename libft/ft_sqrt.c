/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:37:38 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int max;
	int min;
	int mid;

	min = 0;
	mid = 0;
	max = 46340;
	if (nb <= 0)
		return (0);
	while (nb != mid * mid)
	{
		mid = (max + min) / 2;
		if ((max - min) == 1)
			return (0);
		if (nb > mid * mid)
			min = mid;
		else if (nb < mid * mid)
			max = mid;
	}
	return (mid);
}
