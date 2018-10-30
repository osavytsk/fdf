/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:32:53 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exiting_x(void *condit)
{
	(void)condit;
	exit(1);
	return (0);
}

int	rotating(int code_key, t_aprinfo *cond)
{
	t_aprinfo	*data;

	data = cond;
	if (code_key == 88)
		data->param->rot_y += M_PI / 180;
	else if (code_key == 86)
		data->param->rot_y -= M_PI / 180;
	else if (code_key == 84)
		data->param->rot_x += M_PI / 180;
	else if (code_key == 91)
		data->param->rot_x -= M_PI / 180;
	return (0);
}

int	sifting(int keys, t_aprinfo *cond)
{
	t_aprinfo	*d;

	d = cond;
	if (keys == 125 && d->param->shf_y < 2 * d->full_map->window_h)
		d->param->shf_y += d->param->zoom + 1;
	else if (keys == 126 && d->param->shf_y > -2 * d->full_map->window_h)
		d->param->shf_y -= d->param->zoom + 1;
	else if (keys == 124 && d->param->shf_y < 2 * d->full_map->window_w)
		d->param->shf_x += d->param->zoom + 1;
	else if (keys == 123 && d->param->shf_y > -2 * d->full_map->window_w)
		d->param->shf_x -= d->param->zoom + 1;
	return (0);
}

int	zooms(int code_key, t_aprinfo *data)
{
	int width;
	int height;
	int zoom;

	zoom = data->param->zoom;
	width = data->full_map->width;
	height = data->full_map->h;
	if (code_key == 18)
	{
		if (zoom * (width > height ? width : height) + 1500 < 2147483647)
			data->param->zoom++;
		return (0);
	}
	else
	{
		if (zoom > 1)
			data->param->zoom--;
		return (0);
	}
}

int	navigation(int key_n, void *condit)
{
	t_aprinfo	*data;

	data = condit;
	if (key_n == 53)
		exiting_x(data);
	else if (key_n == 88 || key_n == 86 || key_n == 84 || key_n == 91)
		rotating(key_n, data);
	else if (key_n >= 123 && key_n <= 126)
		sifting(key_n, data);
	else if (key_n == 18 || key_n == 19)
		zooms(key_n, data);
	else if (key_n == 49)
	{
		data->param->zoom = data->param->base_zoom;
		data->param->rot_x = 0;
		data->param->rot_y = 0;
		data->param->shf_x = data->full_map->window_w / 2;
		data->param->shf_y = data->full_map->window_h / 2;
	}
	else
		return (0);
	mlx_clear_window(data->window->mlx, data->window->window);
	draw_tab((map_conv(data->full_map, data->param, data->curr_map)),
			data->window, data->full_map);
	return (0);
}
