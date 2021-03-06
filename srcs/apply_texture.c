/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_texture.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:03:08 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 20:36:55 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void			set_textures(t_wolf *wolf)
{
	wolf->tex.walls[0].ptr_img = mlx_xpm_file_to_image(wolf->mlx_ptr,
	"ressources/Mario_brick.xpm", &wolf->tex.walls[0].width,
	&wolf->tex.walls[0].height);
	wolf->tex.walls[0].tab = (int*)mlx_get_data_addr(wolf->tex.walls[0].ptr_img,
	&wolf->tex.walls[0].bpp, &wolf->tex.walls[0].sizeline,
	&wolf->tex.walls[0].endian);
	wolf->tex.walls[1].ptr_img = mlx_xpm_file_to_image(wolf->mlx_ptr,
	"ressources/Mario_Ghost.xpm", &wolf->tex.walls[1].width,
	&wolf->tex.walls[1].height);
	wolf->tex.walls[1].tab = (int*)mlx_get_data_addr(wolf->tex.walls[1].ptr_img,
	&wolf->tex.walls[1].bpp, &wolf->tex.walls[1].sizeline,
	&wolf->tex.walls[1].endian);
	wolf->tex.walls[2].ptr_img = mlx_xpm_file_to_image(wolf->mlx_ptr,
	"ressources/Mario_kappa.xpm", &wolf->tex.walls[2].width,
	&wolf->tex.walls[2].height);
	wolf->tex.walls[2].tab = (int*)mlx_get_data_addr(wolf->tex.walls[2].ptr_img,
	&wolf->tex.walls[2].bpp, &wolf->tex.walls[2].sizeline,
	&wolf->tex.walls[2].endian);
	wolf->tex.walls[3].ptr_img = mlx_xpm_file_to_image(wolf->mlx_ptr,
	"ressources/Mario_mush.xpm", &wolf->tex.walls[3].width,
	&wolf->tex.walls[3].height);
	wolf->tex.walls[3].tab = (int*)mlx_get_data_addr(wolf->tex.walls[3].ptr_img,
	&wolf->tex.walls[3].bpp, &wolf->tex.walls[3].sizeline,
	&wolf->tex.walls[3].endian);
}

void			del_textures(t_wolf *wolf)
{
	int			i;

	i = -1;
	while (++i < 4)
		if (wolf->tex.walls[i].ptr_img != NULL)
			mlx_destroy_image(wolf->mlx_ptr, wolf->tex.walls[i].ptr_img);
}
