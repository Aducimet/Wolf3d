 /* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 16:35:58 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 18:05:16 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_colors(t_wolf *wolf)
{
	if (wolf->b_color == 1)
	{
		wolf->color = wolf->mapcolor[wolf->type][wolf->color_select];
	}
	else
	{
		if (wolf->type == 0 && wolf->raydir.x > 0)
			wolf->tex.id = 0;
		if (wolf->type == 0 && wolf->raydir.x < 0)
			wolf->tex.id = 1;
		if (wolf->type == 1 && wolf->raydir.y > 0)
			wolf->tex.id = 2;
		if (wolf->type == 1 && wolf->raydir.y < 0)
			wolf->tex.id = 3;
	}
}