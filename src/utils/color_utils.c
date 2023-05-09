/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:38:29 by hozdemir          #+#    #+#             */
/*   Updated: 2023/05/06 17:42:08 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

int	get_color(int *color_rgb)
{
	int		total;
	int		i;

	i = 0;
	total = 0;
	while (i < 3)
	{
		if(i == 0)
			total += (color_rgb[i] * 65536);
		else if (i == 1)
			total += (color_rgb[i] * 256);
		else
			total += (color_rgb[i] * 1);
		i++;
	}
	return (total);
}