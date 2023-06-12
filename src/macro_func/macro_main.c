/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturker <rturker@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:00:27 by hozdemir          #+#    #+#             */
/*   Updated: 2023/06/12 14:19:20 by rturker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

static t_bool	macrocomp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (FALSE);
	while ((s1[i] != 0 || s2[i] != 0))
	{
		if (s1[i] != s2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	macro_select(char *str, t_data *data)
{
	if (macrocomp(str, "FILLSTRUCT"))
		return (fillstruct(data));
	else if (macrocomp(str, "MAPSTR"))
		return (mapstr(data));
	else if (macrocomp(str, "SELECT_DIRECTION"))
		return (select_direction(data));
	return (FALSE);
}
