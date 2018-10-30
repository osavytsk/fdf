/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:37:41 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:37:45 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_pre_sort(int argc, char **argv)
{
	int l;
	int c;
	int n;
	char*buff;

	n = 0;
	while (n < argc - 1)
	{
		l = 1;
		while (l < argc - 1)
		{
			c = 0;
			while (argv[l][c] == argv[l + 1][c] &&
			argv[l + 1][c] != '\0' && argv[l][c] != '\0')
				c++;
			if (argv[l][c] - argv[l + 1][c] > 0)
			{
				buff = argv[l];
				argv[l] = argv[l + 1];
				argv[l + 1] = buff;
			}
			l++;
		}
		n++;
	}
}

void		ft_sort(int argc, char **argv)
{
	if (argc && argv)
		ft_pre_sort(argc, argv);
}
