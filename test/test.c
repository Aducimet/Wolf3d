
#include "../wolf3d.h"

static void	set_side_dist(t_env *env)
{
	if (env->player.raydir.x < 0)
	{
		env->step.x = -1;
		env->side_dist.x = (env->player.raypos.x - env->map_x) *
		env->delta_dist.x;
	}
	else
	{
		env->step.x = 1;
		env->side_dist.x = (env->map_x + 1.0 - env->player.raypos.x) *
		env->delta_dist.x;
	}
	if (env->player.raydir.y < 0)
	{
		env->step.y = -1;
		env->side_dist.y = (env->player.raypos.y - env->map_y) *
		env->delta_dist.y;
	}
	else
	{
		env->step.y = 1;
		env->side_dist.y = (env->map_y + 1.0 - env->player.raypos.y) *
		env->delta_dist.y;
	}
}

static void	ray_dist(t_env *env)
{
	env->delta_dist.x = sqrt(1 + (env->player.raydir.y * env->player.raydir.y)
			/ (env->player.raydir.x * env->player.raydir.x));
	env->delta_dist.y = sqrt(1 + (env->player.raydir.x * env->player.raydir.x)
			/ (env->player.raydir.y * env->player.raydir.y));
	set_side_dist(env);
}

static void	ray_test(t_env *env)
{
	env->ray_hit = 0;
	while (env->ray_hit == 0)
	{
		if (env->side_dist.x < env->side_dist.y)
		{
			env->side_dist.x += env->delta_dist.x;
			env->map_x += env->step.x;
			env->type = 0;
		}
		else if (env->side_dist.x >= env->side_dist.y)
		{
			env->side_dist.y += env->delta_dist.y;
			env->map_y += env->step.y;
			env->type = 1;
		}
		else
			env->type = 3;
		if (env->map.coord[env->map_y][env->map_x].value == 1)
			env->ray_hit = 1;
	}
}

void		init_ray(t_env *env, int x)
{
	env->cam = 2 * x / (double)WIN_W - 1;
	env->player.raypos = env->player.pos;
	env->player.raydir.x = env->player.dir.x + env->plane.x * env->cam;
	env->player.raydir.y = env->player.dir.y + env->plane.y * env->cam;
	env->map_x = (int)env->player.raypos.x;
	env->map_y = (int)env->player.raypos.y;
	ray_dist(env);
	ray_test(env);
	if (env->type == 0)
		env->wall_dist = ((env->map_x - env->player.raypos.x +
					(1 - env->step.x) / 2) / env->player.raydir.x) + 0.001;
	else
		env->wall_dist = (env->map_y - env->player.raypos.y +
				(1 - env->step.y) / 2) / env->player.raydir.y + 0.001;
}

void		ray_cast(t_env *env)
{
	int		x;

	x = -1;
	while (++x < WIN_W)
	{
		init_ray(env, x);
		env->map.coord[(int)env->player.pos.y]
			[(int)env->player.pos.x].value = 0;
		env->ray_height = (int)(WIN_H / env->wall_dist);
		env->start = -env->ray_height / 2 + WIN_H / 2;
		env->tex_x = env->wall_dist * 64;
		if (env->start < 0)
			env->start = 0;
		if (env->start > WIN_W)
			env->start = WIN_W - 1;
		env->end = env->ray_height / 2 + WIN_H / 2;
		if (env->end >= WIN_H)
			env->end = WIN_H - 1;
		set_colors(env);
		draw_wall(env, x);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->image.ptr, 0, 0);
} 