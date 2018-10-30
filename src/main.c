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

void			setup_wins(t_window *w, t_chart *m)
{
	m->window_w = 1500;
	m->window_h = 1500;
	w->mlx = mlx_init();
	m->width = m->width;
	if (m->width * (DEFAULT_SCALE + 10) < 1500)
		m->window_w = m->width * (DEFAULT_SCALE + 15);
	if (m->h * (DEFAULT_SCALE + 10) < 1500)
		m->window_h = m->h * (DEFAULT_SCALE + 15);
	w->window = mlx_new_window(w->mlx, m->window_w, m->window_h, "Fdf");
}

void			setup_param(t_prms *cond, t_chart *m)
{
	cond->zoom = DEFAULT_SCALE;
	cond->rot_x = M_PI / 180 * 0;
	cond->rot_y = M_PI / 180 * 0;
	cond->shf_x = m->window_w / 2;
	cond->shf_y = m->window_h / 2;
}

int				mod_set_cond(int ac, char **av, t_prms *cond, t_chart *mp)
{
	int i;

	if (ac == 3)
	{
		if ((i = best_atoi_ever(&(av[2]))) < 1 || *(av[2]) != 0)
			return (0);
		cond->zoom = i;
		cond->base_zoom = i;
	}
	else
	{
		cond->zoom = DEFAULT_SCALE;
		cond->base_zoom = DEFAULT_SCALE;
	}
	cond->rot_x = M_PI / 180 * 0;
	cond->rot_y = M_PI / 180 * 0;
	cond->shf_x = mp->window_w / 2;
	cond->shf_y = mp->window_h / 2;
	return (1);
}

t_aprinfo		*init_info(t_chart *mp, t_prms *cond, t_window *wd)
{
	t_aprinfo *data;

	data = (t_aprinfo *)malloc(sizeof(t_aprinfo));
	data->full_map = mp;
	data->param = cond;
	data->window = wd;
	data->curr_map = conv_map(mp, cond);
	return (data);
}

int				main(int argc, char **argv)
{
	t_window	wd;
	t_chart		*mp;
	t_prms		cond;
	t_aprinfo	*data;

	if (argc == 1 || argc > 4)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size ]\n");
		return (0);
	}
	mp = (t_chart *)malloc(sizeof(t_chart));
	if (!(setup_map(mp, argv)))
		return (0);
	setup_wins(&wd, mp);
	if (!(mod_set_cond(argc, argv, &cond, mp)))
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size ]\n");
		return (solo_destruct(mp, mp->h - 1));
	}
	data = init_info(mp, &cond, &wd);
	draw_tab(data->curr_map, &wd, mp);
	mlx_hook(wd.window, 17, 1L << 17, exiting_x, wd.mlx);
	mlx_hook(wd.window, 2, 666, navigation, data);
	mlx_loop(wd.mlx);
	return (0);
}
