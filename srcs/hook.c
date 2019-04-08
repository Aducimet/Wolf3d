/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hook.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 19:42:03 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 07:27:56 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		move_player(t_wolf *wolf, const int dir)
{
	if (dir == 1)
	{
		if (wolf->map[(int)(wolf->playerpos.y)][(int)(wolf->playerpos.x +
			wolf->dir.x * wolf->speed)] == 0)
			wolf->playerpos.x += wolf->dir.x * wolf->speed;
		if (wolf->map[(int)(wolf->playerpos.y + wolf->dir.y *
			wolf->speed)][(int)(wolf->playerpos.x)]== 0)
			wolf->playerpos.y += wolf->dir.y * wolf->speed;
	}
	if (dir == -1)
	{
		if (wolf->map[(int)(wolf->playerpos.y)][(int)(wolf->playerpos.x
			- wolf->dir.x * wolf->speed)]== 0)
			wolf->playerpos.x -= wolf->dir.x * wolf->speed;
		if (wolf->map[(int)(wolf->playerpos.y - wolf->dir.y
			* wolf->speed)][(int)(wolf->playerpos.x)] == 0)
			wolf->playerpos.y -= wolf->dir.y * wolf->speed;
	}
}

void		move_cam(t_wolf *wolf, const int dir)
{
	double tmp;
	double tmp2;

	tmp = wolf->dir.x;
	tmp2 = wolf->plane.x;
	if (dir == 3)
	{
		wolf->dir.x = wolf->dir.x * cos(-0.04) -
			wolf->dir.y * sin(-0.04);
		wolf->dir.y = tmp * sin(-0.04) + wolf->dir.y * cos(-0.04);
		wolf->plane.x = wolf->plane.x * cos(-0.04) - wolf->plane.y * sin(-0.04);
		wolf->plane.y = tmp2 * sin(-0.04) + wolf->plane.y * cos(-0.04);
	}
	if (dir == 1)
	{
		wolf->dir.x = wolf->dir.x * cos(0.04) -
			wolf->dir.y * sin(0.04);
		wolf->dir.y = tmp * sin(0.04) + wolf->dir.y * cos(0.04);
		tmp2 = wolf->plane.x;
		wolf->plane.x = wolf->plane.x * cos(0.04) - wolf->plane.y * sin(0.04);
		wolf->plane.y = tmp2 * sin(0.04) + wolf->plane.y * cos(0.04);
	}
}

int ft_key_hook_press(int keycode, t_wolf *wolf)
{
	if (keycode == 126)
		wolf->up = 1;
	if (keycode == 125)
		wolf->down = 1;
	if (keycode == 124)
		wolf->right = 1;
	if (keycode == 123)
		wolf->left = 1;
	if (keycode == 257)
		wolf->speed = 0.3;
	if (keycode == 53)
	{
		ft_putendl("Exit program");
		exit(0);
	}
	if (keycode == 69 && wolf->color_select < 4)
		wolf->color_select++;
	if (keycode == 78 && wolf->color_select > 0)
		wolf->color_select--;
	if (keycode == 49)
		wolf->b_color *= -1;
	if (keycode == 17 && wolf->hours == 0)
	{	
		wolf->hours = 1;
		return (1);
	}
	if (keycode == 17 && wolf->hours == 1)
	{
		wolf->hours = 0;
		return (1);
	}
	return (1);
}


int	ft_key_hook_release(int keycode, t_wolf *wolf)
{
	if (keycode == 126)
		wolf->up = 0;
	if (keycode == 125)
		wolf->down = 0;
	if (keycode == 124)
		wolf->right = 0;
	if (keycode == 123)
		wolf->left = 0;
	if (keycode == 257)
		wolf->speed = 0.10;
	return (1);
}

int			cam_move(t_wolf *wolf)
{
	if (wolf->right)
		move_cam(wolf, 3);
	if (wolf->left)
		move_cam(wolf, 1);
	if (wolf->up)
		move_player(wolf, 1);
	if (wolf->down)
		move_player(wolf, -1);
	clear(wolf);
	ft_draw(wolf);
	return (1);
}