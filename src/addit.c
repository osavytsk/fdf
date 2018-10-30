/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:28:51 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 20:28:56 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	cnt_sz(int fd, t_chart *full_map)
{
	char	*s;
	int		wrds;
	int		lns;

	if (get_next_line(fd, &s) == 1)
		wrds = count_wrd(s);
	else
		return (0);
	free(s);
	lns = 1;
	while (get_next_line(fd, &s) == 1)
	{
		if (wrds != count_wrd(s))
			return (-1);
		lns++;
		free(s);
	}
	free(s);
	full_map->width = wrds;
	full_map->h = lns;
	close(fd);
	return (wrds);
}

int	setup_map(t_chart *full_map, char **av)
{
	int				fd;
	char			*line;

	fd = -1;
	line = NULL;
	if ((fd = open(av[1], O_RDWR)) < 0)
	{
		perror("");
		return (0);
	}
	if (cnt_sz(fd, full_map) < 0)
	{
		ft_putstr("Wrong file format\n");
		return (0);
	}
	full_map->mappa = (t_point **)malloc(sizeof(t_point *) * (full_map->h + 1));
	if ((fd = open(av[1], O_RDWR)) < 0)
		return (0);
	if (!dirt_job(fd, line, full_map))
	{
		ft_putstr("Wrong file format\n");
		return (0);
	}
	close(fd);
	return (1);
}
