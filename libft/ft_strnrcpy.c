/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnrcpy.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 18:22:34 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 18:25:50 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrcpy(char *dest, const char *src, size_t len)
{
	size_t i;

	i = len;
	while (src[i])
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	ft_bzero(dest + i, len - i);
	return (dest);
}
