/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 15:08:55 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 10:56:25 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_side_dist(t_wolf *wolf)
{
	if (wolf->raydir.x < 0)
	{
		wolf->step.x = -1;
		wolf->sidedist.x = (wolf->raypos.x - wolf->mapx) * wolf->deltadist.x;
	}
	else
	{
		wolf->step.x = 1;
		wolf->sidedist.x = (wolf->mapx + 1.0 - wolf->raypos.x) *
		wolf->deltadist.x;
	}
	if (wolf->raydir.y < 0)
	{
		wolf->step.y = -1;
		wolf->sidedist.y = (wolf->raypos.y - wolf->mapy) * wolf->deltadist.y;
	}
	else
	{
		wolf->step.y = 1;
		wolf->sidedist.y = (wolf->mapy + 1.0 - wolf->raypos.y) *
		wolf->deltadist.y;
	}
}

void		ft_find_ray_dist(t_wolf *wolf)
{
	wolf->deltadist.x = sqrt(1 + (wolf->raydir.y * wolf->raydir.y) /
	(wolf->raydir.x * wolf->raydir.x)); // a modifier (creer fonction)
	wolf->deltadist.y = sqrt(1 + (wolf->raydir.x * wolf->raydir.x) /
	(wolf->raydir.y * wolf->raydir.y));
	ft_side_dist(wolf);
}

void		ft_ray_check(t_wolf *wolf)
{
	wolf->hit = 0;
	while (wolf->hit == 0)
	{
		if (wolf->sidedist.x < wolf->sidedist.y)
		{
			wolf->sidedist.x += wolf->deltadist.x;
			wolf->mapx += wolf->step.x;
			wolf->type = 0;
		}
		else if (wolf->sidedist.x >= wolf->sidedist.y)
		{
			wolf->sidedist.y += wolf->deltadist.y;
			wolf->mapy += wolf->step.y;
			wolf->type = 1;
		}
		else
			wolf->type = 3;
		if (wolf->map[wolf->mapy][wolf->mapx] == 1)
			wolf->hit = 1;
	}
}

void		define_ray(t_wolf *wolf, int x)
{
	wolf->camera = 2 * x / (double)wolf->win_size_x - 1;
	wolf->raypos.x = wolf->playerpos.x;
	wolf->raypos.y = wolf->playerpos.y;
	wolf->raydir.x = wolf->dir.x + wolf->plane.x * wolf->camera;
	wolf->raydir.y = wolf->dir.y + wolf->plane.y * wolf->camera;
	wolf->mapx = (int)wolf->raypos.x;
	wolf->mapy = (int)wolf->raypos.y;
	ft_find_ray_dist(wolf);
	ft_ray_check(wolf);
	if (wolf->type == 0)
	{
		wolf->walldist = ((wolf->mapx - wolf->raypos.x +
		(1 - wolf->step.x) / 2) / wolf->raydir.x) + 0.001;
	}
	else
	{
		wolf->walldist = (wolf->mapy - wolf->raypos.y +
		(1 - wolf->step.y) / 2) / wolf->raydir.y + 0.001;
	}
}

void		ft_draw(t_wolf *wolf)
{
	int x;

	x = 0;
	while (x < wolf->win_size_x)
	{
		define_ray(wolf, x);
		wolf->map[(int)wolf->playerpos.y][(int)wolf->playerpos.x] = 0;
		wolf->rayheight = (int)(wolf->win_size_y / wolf->walldist);
		wolf->start = -wolf->rayheight / 2 + wolf->win_size_y / 2;
		if (wolf->start < 0)
			wolf->start = 0;
		if (wolf->start > wolf->win_size_x)
			wolf->start = wolf->win_size_x - 1;
		wolf->end = wolf->rayheight / 2 + wolf->win_size_y / 2;
		if (wolf->end >= wolf->win_size_y)
			wolf->end = wolf->win_size_y - 1;
		set_colors(wolf);
		draw_wall(wolf, x);
		x++;
	}
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr,
	wolf->img.ptr_img, 0, 0);
	ft_hud(wolf);
}
