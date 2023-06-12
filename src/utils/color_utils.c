/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturker <rturker@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:38:29 by hozdemir          #+#    #+#             */
/*   Updated: 2023/06/12 13:55:41 by rturker          ###   ########.fr       */
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
		if (i == 0)
			total += (color_rgb[i] * 65536);
		else if (i == 1)
			total += (color_rgb[i] * 256);
		else
			total += (color_rgb[i] * 1);
		i++;
	}
	return (total);
}
