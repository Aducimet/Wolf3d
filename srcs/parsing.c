/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/12 16:42:02 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 16:29:47 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_get_info_map(t_wolf *wolf)
{
	int	x;
	int	y;
	int	flag;

	x = 0;
	y = 0;
	flag = 0;
	while (y++ < wolf->map_size_y)
	{
		x = 0;
		while (x++ < wolf->map_size_x)
		{
			if (wolf->map[y][x] == 3)
			{
				wolf->playerpos.x = (double)x;
				wolf->playerpos.y = (double)y;
				flag++;
			}
		}
	}
	if (flag != 1)
	{
		ft_putendl("Error SpawnPoint");
		exit(0);
	}
}

void	ft_square_check_x(t_wolf *wolf, int x, int y)
{
	while (x < wolf->map_size_x)
	{
		if (wolf->map[y][x] != 1)
		{
			ft_putendl("Error square map");
			exit(0);
		}
		x++;
	}
}

void	ft_square_check_y(t_wolf *wolf, int x, int y)
{
	while (y < wolf->map_size_y)
	{
		if (wolf->map[y][x] != 1)
		{
			ft_putendl("Error square map");
			exit(0);
		}
		y++;
	}
}

void	ft_square_map(t_wolf *wolf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_square_check_x(wolf, x, y);
	x = 0;
	ft_square_check_y(wolf, x, y);
	y = wolf->map_size_y - 1;
	x = 0;
	ft_square_check_x(wolf, x, y);
	x = wolf->map_size_x - 1;
	y = 0;
	ft_square_check_y(wolf, x, y);
}

void	ft_do_parsing(t_wolf *wolf)
{
	ft_get_info_map(wolf);
	ft_square_map(wolf);
}
