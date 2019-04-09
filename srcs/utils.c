/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 18:38:34 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 16:05:24 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

t_wolf		*define_wolf(void)
{
	t_wolf	*wolf;

	if (!(wolf = (t_wolf *)malloc(sizeof(t_wolf))))
		return (NULL);
	return (wolf);
}

void		ft_tab_len_error(t_wolf *wolf, char **tmp)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (tmp[x])
	{
		x++;
	}
	if (wolf->map_size_x != x)
	{
		ft_putendl("Error len map");
		exit(0);
	}
}

void		ft_check_char(char **line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i][0] != '1' && line[i][0] != '0' && line[i][0] != '3')
		{
			ft_putendl("Error char map");
			exit(0);
		}
		i++;
	}
}

void		ft_check_map_name(char *tab)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (tab[i])
		i++;
	tmp = ft_strsub(tab, i - 4, 4);
	if (ft_strcmp(tmp, ".w3d") != 0)
	{
		ft_putendl("Invalid type of argument");
		exit(0);
	}
}
