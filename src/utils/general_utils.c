/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:10:35 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/06 11:11:24 by hozdemir         ###   ########.fr       */
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

void	error_print(char *error_msg)
{
	printf("%s\n", error_msg);
	exit (0);
}