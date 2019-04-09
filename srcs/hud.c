/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 19:37:43 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 15:57:42 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_hud_color(int i)
{
	int tab[6];

	tab[0] = RGB(0, 0, 0);
	tab[1] = RGB(255, 0, 0);
	tab[2] = RGB(0, 0, 255);
	tab[3] = RGB(0, 0, 0);
	tab[4] = RGB(0, 0, 255);
	tab[5] = RGB(255, 0, 0);
	return (tab[i]);
}

void		ft_hud(t_wolf *wolf)
{
	double	x;
	double	y;
	char	*tab[6];
	int		i;
	int		color;

	i = -1;
	x = 1275;
	y = 900;
	tab[0] = ft_strjoin("MapName = ", wolf->mapname);
	tab[1] = "Move = Arrows";
	tab[2] = "Change hours = T";
	tab[3] = "Change color = +/-";
	tab[4] = "Texture On/Off = SPACE";
	tab[5] = "Sprint = LSHIFT";
	while (++i < 6)
	{
		color = ft_hud_color(i);
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, x, y, color, tab[i]);
		y += 20;
	}
}
