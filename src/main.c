/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:32:56 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_window(t_win *wind, t_map *map)
{
	map->win_w = 1500;
	map->win_h = 1500;
	wind->mlx = mlx_init();
	map->w = map->w;
	if (map->w * (DEFAULT_SCALE + 10) < 1500)
		map->win_w = map->w * (DEFAULT_SCALE + 15);
	if (map->h * (DEFAULT_SCALE + 10) < 1500)
		map->win_h = map->h * (DEFAULT_SCALE + 15);
	wind->win = mlx_new_window(wind->mlx, map->win_w, map->win_h, "Fdf");
}

void		init_params(t_par *param, t_map *map)
{
	param->scale = DEFAULT_SCALE;
	param->rotate_x = M_PI / 180 * 0;
	param->rotate_y = M_PI / 180 * 0;
	param->shift_x = map->win_w / 2;
	param->shift_y = map->win_h / 2;
}

int			mod_init_params(int argc, char **argv, t_par *param, t_map *map)
{
	int i;

	if (argc == 3)
	{
		if ((i = cancer_atoi(&(argv[2]))) < 1 || *(argv[2]) != 0)
			return (0);
		param->scale = i;
		param->basic_scale = i;
	}
	else
	{
		param->scale = DEFAULT_SCALE;
		param->basic_scale = DEFAULT_SCALE;
	}
	param->rotate_x = M_PI / 180 * 0;
	param->rotate_y = M_PI / 180 * 0;
	param->shift_x = map->win_w / 2;
	param->shift_y = map->win_h / 2;
	return (1);
}

t_apr		*init_info(t_map *map, t_par *param, t_win *wind)
{
	t_apr *info;

	info = (t_apr *)malloc(sizeof(t_apr));
	info->fmap = map;
	info->param = param;
	info->win = wind;
	info->cmap = convert_map(map, param);
	return (info);
}

int			main(int argc, char **argv)
{
	t_win wind;
	t_map *map;
	t_par param;
	t_apr *info;

	if (argc == 1 || argc > 4)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size ]\n");
		return (0);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!(init_map(map, argv)))
		return (0);
	init_window(&wind, map);
	if (!(mod_init_params(argc, argv, &param, map)))
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size ]\n");
		return (self_destruction(map, map->h - 1));
	}
	info = init_info(map, &param, &wind);
	draw_map(info->cmap, &wind, map);
	mlx_hook(wind.win, 17, 1L << 17, exit_x, wind.mlx);
	mlx_hook(wind.win, 2, 666, control, info);
	mlx_loop(wind.mlx);
	return (0);
}
