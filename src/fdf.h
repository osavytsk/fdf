/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/30 18:32:49 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define DEFAULT_SCALE 30
# define B 0
# define G 1
# define R 2
# define D 3

typedef union		u_color
{
	unsigned int	i_color;
	unsigned char	space[4];
}					t_color;

typedef struct		s_point
{
	int			x;
	int			y;
	int			z;
	t_color		color;
}					t_point;

typedef struct		s_std
{
	int			x;
	int			y;
	t_color		color;
}					t_std;

typedef struct		s_chart
{
	int			window_w;
	int			window_h;
	int			width;
	int			h;
	t_point		**mappa;
}					t_chart;

typedef struct		s_window
{
	void		*mlx;
	void		*window;
}					t_window;

typedef struct		s_prms
{
	int			base_zoom;
	int			zoom;
	int			shf_x;
	int			shf_y;
	float		rot_x;
	float		rot_y;
}					t_prms;

typedef struct		s_aprinfo
{
	t_chart		*full_map;
	t_prms		*param;
	t_window	*window;
	t_std		**curr_map;
}					t_aprinfo;

typedef struct		s_rotate
{
	float		sinus_x;
	float		sinus_y;
	float		cosinus_x;
	float		cosinus_y;
	float		rot_asis;
}					t_rotate;

void				draw_tab(t_std **mp, t_window *wdw, t_chart *fl_mp);
t_std				**map_conv(t_chart *fl_mp, t_prms *f_cond, t_std **cr_mp);
int					best_atoi_ever(char **s);
t_std				**conv_map(t_chart *full_map, t_prms *f_param);
int					setup_map(t_chart *full_map, char **av);
int					solo_destruct(t_chart *full_map, int i);
int					exiting_x(void *condit);
int					navigation(int key_n, void *condit);
int					float_power(int n, int p);
int					dirt_job(int fd, char *l, t_chart *full_map);
int					cnt_sz(int fd, t_chart *full_map);
int					count_wrd(char *s);

#endif
