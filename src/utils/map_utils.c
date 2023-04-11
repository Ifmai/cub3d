/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:30:07 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/11 09:08:49 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

int	check_file_extention(char *path)
{
	char	*check;
	int		i;

	i = 0;
	check = "buc.";
	while(path[i + 1] != 0)
		i++;
	while (*check != 0)
	{
		if (path[i] != *check)
			return (0);
		check++;
		i--;
	}
	return (1);
}

static int		cub_lenght(char *path)
{
	char	*buffer;
	int		i;
	int		fd;

	i = 0;
	fd = open(path, O_RDONLY);
	buffer = get_next_line(fd);
	while(1)
	{
		i++;
		free(buffer);
		buffer = get_next_line(fd);
		if(!buffer)
			break;
	}
	close(fd);
	return (i + 1);
}

static char		**temp_create(char *path, int len)
{
	char	**temp;
	int		i;
	int		fd;

	i = 0;
	temp = malloc(sizeof(char *) * len);
	fd = open(path, O_RDONLY);
	while(i < len)
	{
		temp[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (temp);
}

int	lenght_find(char *path)
{
	char	**temp_cub;
	int		len;
	int		temp_len;
	int		i;
	int		j;

	i = 0;
	len = 0;
	temp_len = cub_lenght(path);
	temp_cub = temp_create(path, temp_len);
	while(temp_cub[i] != 0)
	{
		j = 0;
		if(temp_cub[i][j] &&
			(temp_cub[i][j] != 'N' && temp_cub[i][j] != 'S' && \
			temp_cub[i][j] != 'W' && temp_cub[i][j] != 'E' && \
			temp_cub[i][j] != 'C' && temp_cub[i][j] != 'F'))
			len++;
		i++;
	}
	free_double_array(temp_cub);
	return (len + 1);
}
