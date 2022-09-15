/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:45:47 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/15 14:40:54 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->position[0] - 1][vars->position[1]] != '1')
	{
		if (actions(&vars->map[vars->position[0]][vars->position[1]],
			&vars->map[vars->position[0] - 1][vars->position[1]], vars))
			vars->position[0]--;
	}
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->position[0]][vars->position[1] - 1] != '1')
	{
		if (actions(&vars->map[vars->position[0]][vars->position[1]],
			&vars->map[vars->position[0]][vars->position[1] - 1], vars))
			vars->position[1]--;
	}
	if (vars->game_over == 0)
	{
		mlx_destroy_image(vars->mlx, vars->sonic);
		vars->sonic = mlx_xpm_file_to_image(vars->mlx,
				"../img/s_wait_a.xpm", &vars->img_width, &vars->img_height);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->position[0] + 1][vars->position[1]] != '1')
	{
		if (actions(&vars->map[vars->position[0]][vars->position[1]],
			&vars->map[vars->position[0] + 1][vars->position[1]], vars))
			vars->position[0]++;
	}
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->position[0]][vars->position[1] + 1] != '1')
	{
		if (actions(&vars->map[vars->position[0]][vars->position[1]],
			&vars->map[vars->position[0]][vars->position[1] + 1], vars))
			vars->position[1]++;
	}
	if (vars->game_over == 0)
	{
		mlx_destroy_image(vars->mlx, vars->sonic);
		vars->sonic = mlx_xpm_file_to_image(vars->mlx,
				"../img/s_wait_d.xpm", &vars->img_width, &vars->img_height);
	}
}
