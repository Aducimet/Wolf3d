/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   define_wolf3d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/05 22:23:57 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 07:46:02 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_colors(t_wolf *wolf)
{
	wolf->mapcolor[3][0] = RGB(68, 175, 235); // ciel bleu clair
	wolf->mapcolor[3][1] = RGB(1, 6, 87);	// ciel bleu fonce
	wolf->mapcolor[2][0] = RGB(255, 228, 196); // sol
	wolf->mapcolor[1][0] = RGB(239, 155, 15); //mur face
	wolf->mapcolor[0][0] = RGB(63, 34, 4);
	wolf->mapcolor[2][1] = RGB(201, 160, 220);
	wolf->mapcolor[1][1] = RGB(150, 131, 236);
	wolf->mapcolor[0][1] = RGB(102, 0, 255);
	wolf->mapcolor[2][2] = RGB(251, 242, 183);
	wolf->mapcolor[1][2] = RGB(233, 201, 177); //(233, 201, 177)
	wolf->mapcolor[0][2] = RGB(86, 130, 3);
	wolf->mapcolor[2][3] = RGB(245, 245, 220); //RGB(68, 175, 235)
	wolf->mapcolor[1][3] = RGB(187, 210, 225);
	wolf->mapcolor[0][3] = RGB(48, 48, 48);
	wolf->mapcolor[2][4] = RGB(255, 255, 255);
	wolf->mapcolor[1][4] = RGB(239, 239, 239);
	wolf->mapcolor[0][4] = RGB(0, 0, 0);
}

void	ft_define_value(t_wolf *wolf)
{
	wolf->tex_x = 0;
	wolf->tex_y = 0;
	wolf->tex.id = 0;
	set_textures(wolf);
	wolf->dir.x = -1;
	wolf->dir.y = 0;
	wolf->camera = 0;
	wolf->plane.x = 0;
	wolf->plane.y = 0.66;
	wolf->step.x = 0;
	wolf->step.y = 0;
	wolf->speed = 0.10;
	wolf->right = 0;
	wolf->up = 0;
	wolf->left = 0;
	wolf->down = 0;
	wolf->color_select = 0;
	wolf->b_color = -1;
	wolf->hours = 0;
}

t_img	define_img(void *mlx_ptr, int win_size_x, int win_size_y)
{
	t_img	img;
	
	img.ptr_img = mlx_new_image(mlx_ptr, win_size_x, win_size_y);
	img.tab = (int*)mlx_get_data_addr(img.ptr_img, &(img.bpp),
			&(img.s_l), &(img.endian));
	return (img);
}

t_wolf	*ft_define_wolf3d(void)
{	
	t_wolf *wolf;

	if (!(wolf = (t_wolf *)malloc(sizeof(t_wolf))))
		return (NULL);
	wolf->win_size_x = 1920;
	wolf->win_size_y = 1080;
	wolf->mlx_ptr = mlx_init();
	wolf->win_ptr = mlx_new_window(wolf->mlx_ptr, wolf->win_size_x, wolf->win_size_y, "Wolf3d || Aducimet");
	wolf->img = define_img(wolf->mlx_ptr, wolf->win_size_x, wolf->win_size_y);
	ft_define_value(wolf);
	init_colors(wolf);
	return(wolf);
}
