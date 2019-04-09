/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hook_2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 15:45:41 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 15:54:01 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key_hook_press_hours(int keycode, t_wolf *wolf)
{
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
