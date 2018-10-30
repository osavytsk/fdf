/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:33:45 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long int	sum;
	int					d;

	sum = 0;
	d = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
	*str == '\f' || *str == '\n' || *str == '\r')
		str++;
	if (*str == '-')
	{
		d = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (unsigned long int)(*str - '0');
		if (sum >= 9223372036854775807 && d == 1)
			return (-1);
		else if (sum > 9223372036854775807 && d == -1)
			return (0);
		str++;
	}
	return ((int)((int)sum * d));
}
