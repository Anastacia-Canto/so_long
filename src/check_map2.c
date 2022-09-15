/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:28:51 by ansilva-          #+#    #+#             */
/*   Updated: 2022/09/15 14:48:42 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Count the elements and save player position*/
void	count_elements(t_vars *vars)
{
	if (vars->map[vars->line][vars->col] == 'C')
		vars->count_c++;
	if (vars->map[vars->line][vars->col] == 'P')
	{
		if (vars->count_p == 0)
		{
			vars->position[0] = vars->line;
			vars->position[1] = vars->col;
		}
		else
			vars->map[vars->line][vars->col] = '0';
		vars->count_p++;
	}
	if (vars->map[vars->line][vars->col] == 'E')
		vars->count_e++;
}

/*Check if the map is surrounded by walls and has only 01PCE characters*/
int	check_boundaries_and_content(t_vars *vars)
{
	vars->line = 0;
	while (vars->line < vars->height)
	{
		vars->col = 0;
		while (vars->col < vars->width)
		{
			if (vars->map[0][vars->col] != '1'
			|| vars->map[vars->height - 1][vars->col] != '1'
			|| vars->map[vars->line][0] != '1'
				|| vars->map[vars->line][vars->width - 1] != '1')
				return (0);
			if (vars->map[vars->line][vars->col] != '1'
				&& vars->map[vars->line][vars->col] != '0'
				&& vars->map[vars->line][vars->col] != 'C'
				&& vars->map[vars->line][vars->col] != 'P'
				&& vars->map[vars->line][vars->col] != 'E')
				return (0);
			count_elements(vars);
			vars->col++;
		}
		vars->line++;
	}
	return (1);
}

/*Check if the map is rectangular*/
int	check_shape(t_vars *vars)
{
	int	width;
	int	index;

	if (!vars->map[0])
		return (0);
	width = (int)ft_strlen(vars->map[0]);
	index = 0;
	while (index < vars->height)
	{
		if ((int)ft_strlen(vars->map[index]) != width)
			return (0);
		index++;
	}
	vars->width = width;
	return (1);
}
