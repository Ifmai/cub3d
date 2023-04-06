/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:30:07 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/06 10:15:22 by hozdemir         ###   ########.fr       */
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
	while (*check)
	{
		if (path[i] != *check)
			return (1);
		check++;
		i--;
	}
	return (0);
}

void	error_print(char *error_msg)
{
	printf("%s\n", error_msg);
	exit (0);
}