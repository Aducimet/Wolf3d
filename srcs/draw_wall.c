/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_wall.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 18:28:28 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 10:16:41 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void				put_pixel(t_wolf *wolf, double x, double y, int color)
{
	if ((x >= 0 && x < wolf->win_size_x) && (y >= 0 && y < wolf->win_size_y))
		wolf->img.tab[((int)y * wolf->win_size_x + (int)x)] = color;
}

void	put_pixel_tex(t_wolf *wolf, double x, double y,
					t_img texture)
{
	wolf->tex_y = ((y - wolf->win_size_y * 0.5f + wolf->rayheight * 0.5f) * texture.height) / wolf->rayheight - 0.5;
	if ((x >= 0 && x <= wolf->win_size_x) && (y >= 0 && y <= wolf->win_size_y))
		wolf->img.tab[((int)y * wolf->win_size_x + (int)x)] = texture.tab[(texture.height * (int)wolf->tex_y + (int)wolf->tex_x)];
}

void	put_pixel_sky(t_wolf *wolf, double x, double y,
					t_img texture)
{	
	wolf->tex_y = ((y - wolf->win_size_y * 0.1 + wolf->rayheight * 0.1) * texture.height) / wolf->rayheight - 0.1;
	if ((x > 0 && x < wolf->win_size_x) && (y > 0 && y < wolf->win_size_y))
		wolf->img.tab[((int)y * wolf->win_size_x + (int)x)] = texture.tab[(texture.height * (int)wolf->tex_y + (int)wolf->tex_x)];
}

void				draw_wall(t_wolf *wolf, int x)
{
	int tmp;

	tmp = -1;
	if (wolf->type == 0)
		wolf->tex_x = wolf->raypos.y + wolf->walldist *
		wolf->raydir.y;
	else
		wolf->tex_x = wolf->raypos.x + wolf->walldist *
		wolf->raydir.x;
	wolf->tex_x -= floor(wolf->tex_x);
	wolf->tex_x *= (double)wolf->tex.walls[wolf->tex.id].height;
	while (++tmp <= wolf->start)
		put_pixel(wolf, x, tmp, wolf->mapcolor[3][wolf->hours]);
	while (++tmp <= wolf->end)
	{
		if (wolf->b_color == -1)
			put_pixel_tex(wolf, x, tmp, wolf->tex.walls[wolf->tex.id]);
		else
			put_pixel(wolf, x, tmp,
			wolf->mapcolor[wolf->type][wolf->color_select]);
	}
	while (++tmp <= wolf->win_size_y)
		put_pixel(wolf, x, tmp,
		wolf->mapcolor[2][wolf->color_select]);
}

void				clear(t_wolf *wolf)
{
	ft_bzero(wolf->img.tab, wolf->win_size_x * wolf->win_size_y * 4);
}