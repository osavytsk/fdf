/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:35:28 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	check_resid(char **residue, char **buff, char **line)
{
	char *start;
	char *tmp;

	if ((start = ft_strchr(*buff, '\n')) && *start)
	{
		tmp = ft_strnew((size_t)(ft_strlen(*line) + start - *buff));
		ft_strcpy(tmp, *line);
		free(*line);
		ft_strncat(tmp, *buff, (int)(start - *buff));
		*line = tmp;
		tmp = ft_strnew(ft_strlen(*buff) - (size_t)(start - *buff) - 1);
		ft_strcpy(tmp, start + 1);
		free(*residue);
		*residue = tmp;
		return (1);
	}
	tmp = ft_strnew((size_t)(ft_strlen(*line) + ft_strlen(*buff)));
	ft_strcpy(tmp, *line);
	free(*line);
	ft_strcat(tmp, *buff);
	*line = tmp;
	free(*residue);
	(*residue) = ft_strnew(0);
	return (0);
}

int	read_and_check(t_gnl *fd_store, char **buff, char **line)
{
	int i;

	while ((i = (int)read(fd_store->fd, *buff, BUFF_SIZE)) > 0)
	{
		(*buff)[i] = '\0';
		if (check_resid(&(fd_store->residue), buff, line) || i < BUFF_SIZE)
		{
			free(*buff);
			return (1);
		}
	}
	free(*buff);
	if (i < 0)
	{
		free(fd_store->residue);
		fd_store->residue = ft_strnew(0);
		return (-1);
	}
	if (i == 0 && ft_strlen(*line) > 0)
	{
		free(fd_store->residue);
		fd_store->residue = ft_strnew(0);
		return (1);
	}
	return (0);
}

int	find_and_read(t_gnl *fd_store, int fd, char **line, char **buff)
{
	while (1)
	{
		if (fd_store->fd == fd)
		{
			if (check_resid(&(fd_store->residue), &(fd_store->residue), line))
			{
				free(*buff);
				return (1);
			}
			break ;
		}
		else if (fd_store->next == NULL)
		{
			fd_store->next = (t_gnl *)malloc(sizeof(t_gnl));
			fd_store = fd_store->next;
			fd_store->fd = fd;
			fd_store->next = NULL;
			fd_store->residue = ft_strnew(0);
			break ;
		}
		fd_store = fd_store->next;
	}
	return (read_and_check(fd_store, buff, line));
}

int	get_next_line(const int fd, char **line)
{
	static t_gnl			*fd_store;
	char					*buff;
	t_gnl					*tmp;

	*line = ft_strnew(0);
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!fd_store)
	{
		fd_store = (t_gnl *)malloc(sizeof(t_gnl));
		fd_store->fd = fd;
		fd_store->next = NULL;
		fd_store->residue = ft_strnew(0);
	}
	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	buff[BUFF_SIZE] = '\0';
	tmp = fd_store;
	return (find_and_read(tmp, fd, line, &buff));
}
