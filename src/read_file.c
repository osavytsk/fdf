/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:33:04 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	f_pow(int num, int p)
{
	int res;

	res = 1;
	while (p)
	{
		res = res * num;
		p--;
	}
	return (res);
}

int	self_destruction(t_map *fmap, int i)
{
	while (i >= 0)
	{
		free(fmap->map[i]);
		i--;
	}
	free(fmap->map);
	return (0);
}

int	cou_words(char *str)
{
	int col;
	int r;

	r = 0;
	col = 0;
	if (str[0] != ' ' && str[0] != '\t')
	{
		col++;
		r++;
	}
	while (str[r] != '\0')
	{
		if ((str[r] != ' ' && str[r] != '\t') && (str[r - 1] == ' ' ||
		str[r - 1] == '\t'))
			col++;
		r++;
	}
	return (col);
}

int	count_size(int fd, t_map *fmap)
{
	char	*line;
	int		words;
	int		lines;

	if (get_next_line(fd, &line) == 1)
		words = cou_words(line);
	else
		return (0);
	free(line);
	lines = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (words != cou_words(line))
			return (-1);
		lines++;
		free(line);
	}
	free(line);
	fmap->w = words;
	fmap->h = lines;
	close(fd);
	return (words);
}

int	init_map(t_map *fmap, char **argv)
{
	int				fd;
	char			*line;

	fd = -1;
	line = NULL;
	if ((fd = open(argv[1], O_RDWR)) < 0)
	{
		perror("");
		return (0);
	}
	if (count_size(fd, fmap) < 0)
	{
		ft_putstr("Wrong file format\n");
		return (0);
	}
	fmap->map = (t_dot **)malloc(sizeof(t_dot *) * (fmap->h + 1));
	if ((fd = open(argv[1], O_RDWR)) < 0)
		return (0);
	if (!dirty_work(fd, line, fmap))
	{
		ft_putstr("Wrong file format\n");
		return (0);
	}
	close(fd);
	return (1);
}
