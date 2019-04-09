/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 15:46:01 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 16:28:48 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define ABS(x)  ( (x<0) ? -(x) : x )
# define RGB(r,g,b) (r << 16) + (g << 8) + (b)

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_img
{
	void			*ptr_img;
	int				bpp;
	int				s_l;
	int				endian;
	int				*tab;
	int				width;
	int				height;
	int				sizeline;
}					t_img;

typedef struct		s_texture
{
	t_img			walls[5];
	uint8_t			id;
}					t_texture;

typedef struct		s_wolf
{
	t_img			img;
	t_point			playerpos;
	t_point			plane;
	t_point			step;
	t_point			dir;
	t_point			side;
	t_point			raydir;
	t_point			deltadist;
	t_point			raypos;
	t_point			sidedist;
	t_texture		tex;
	void			*mlx_ptr;
	void			*win_ptr;
	int				**map;
	int				mapcolor[4][5];
	int				map_size_y;
	int				map_size_x;
	int				win_size_x;
	int				win_size_y;
	int				mapx;
	int				mapy;
	int				hit;
	int				type;
	int				rayhit;
	int				start;
	int				end;
	int				color;
	int				b_color;
	int				color_select;
	int				up;
	int				down;
	int				left;
	int				right;
	int				hours;
	double			rayheight;
	double			walldist;
	double			camera;
	double			tex_x;
	double			tex_y;
	double			speed;
	char			*mapname;
}					t_wolf;

t_wolf				*ft_define_wolf3d();
void				ft_square_map(t_wolf *wolf);
void				ft_tab_len_error(t_wolf *wolf, char **tmp);
void				ft_draw(t_wolf *wolf);
void				ft_get_info_map(t_wolf *wolf);
void				clear(t_wolf *wolf);
void				init_colors(t_wolf *wolf);
void				set_textures(t_wolf *wolf);
void				clear(t_wolf *wolf);
void				draw_wall(t_wolf *wolf, int x);
void				set_colors(t_wolf *wolf);
void				put_pixel(t_wolf *wolf, double x, double y, int color);
void				ft_hud(t_wolf *wolf);
void				ft_check_char(char **line);
void				ft_check_map_name(char *tab);
void 				ft_do_parsing(t_wolf *wolf);

int					ft_key_hook_press(int keycode, t_wolf *wolf);
int					ft_key_hook_release(int keycode, t_wolf *wolf);
int					ft_cam_move(t_wolf *wolf);
int					cam_move(t_wolf *wolf);
int					ft_key_hook_press_hours(int keycode, t_wolf *wolf);

#endif
