/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 20:09:57 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/13 20:10:25 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

double	ft_fsqrt(double n, double prec)
{
	double	min;
	double	max;
	double	test;

	min = 0.0;
	max = 46341.0;
	test = (max - min) / 2.0 + min;
	while (test * test != n)
	{
		if (test * test > n)
			max = test;
		if (test * test < n)
			min = test;
		if (max - min < prec)
			return (max);
		test = (max - min) / 2.0 + min;
	}
	return (test);
}
