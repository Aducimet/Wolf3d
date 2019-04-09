/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 15:45:29 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 16:29:12 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		count_line(t_wolf *wolf, int fd1)
{
	int		ret;
	int		count;
	char	*line;
	int		len;

	count = 0;
	while ((ret = get_next_line(fd1, &line)) > 0)
	{
		if (count == 0)
		{
			wolf->map_size_x = ((ft_strlen(line) + 1) / 2);
			len = ((ft_strlen(line) + 1) / 2);
		}
		if (wolf->map_size_x != len || ret == -1)
		{
			ft_putendl("Error map");
			exit(0);
		}
		free(line);
		count++;
	}
	wolf->map_size_y = count;
}

int			ft_read_map(t_wolf *wolf, int fd, int fd1)
{
	char	*line;
	int		len;
	char	**tmp;
	int		index;

	index = 0;
	count_line(wolf, fd1);
	if (!(wolf->map = (int **)malloc(sizeof(int *) * (wolf->map_size_y))))
		return (-1);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!(wolf->map[index] = (int *)malloc(sizeof(int ) *
			(wolf->map_size_x))))
			return (-1);
		tmp = ft_strsplit(line, ' ');
		ft_check_char(tmp);
		ft_tab_len_error(wolf, tmp);
		free(line);
		len = -1;
		while (++len < wolf->map_size_x)
			wolf->map[index][len] = (int)ft_atoi(tmp[len]);
		index++;
	}
	ft_do_parsing(wolf);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		fd1;
	t_wolf	*wolf;

	if (argc == 2)
	{
		ft_check_map_name(argv[1]);
		if (((fd = open(argv[1], O_RDONLY)) <= 0) ||
			((fd1 = open(argv[1], O_RDONLY)) <= 0))
			return (-1);
		if ((wolf = ft_define_wolf3d()) == NULL)
			return (-1);
		wolf->mapname = argv[1];
		ft_read_map(wolf, fd, fd1);
		ft_draw(wolf);
		mlx_hook(wolf->win_ptr, 2, 0, ft_key_hook_press, wolf);
		mlx_hook(wolf->win_ptr, 3, 0, ft_key_hook_release, wolf);
		mlx_loop_hook(wolf->mlx_ptr, cam_move, wolf);
		mlx_loop(wolf->mlx_ptr);
	}
	else
		ft_putendl("Usage ./wolf3d need one argument.");
	return (0);
}
