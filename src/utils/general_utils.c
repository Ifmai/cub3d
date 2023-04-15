/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:10:35 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/15 17:37:45 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

void	free_double_array(char **free_array)
{
	int	i;

	i = 0;
	if (!free_array)
		return ;
	while (free_array[i] != 0)
	{
		free(free_array[i]);
		i++;
	}
	free(free_array);
}

int	double_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error_print(char *error_msg)
{
	printf("%s\n", error_msg);
	exit (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
	printf("burdayım");

	return (total);
}