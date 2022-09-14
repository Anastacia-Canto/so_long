/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:29:15 by ansilva-          #+#    #+#             */
/*   Updated: 2022/09/14 15:12:44 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images(t_vars *vars)
{
	vars->free_way = mlx_xpm_file_to_image(vars->mlx,
			"./img/free_way64.xpm", &vars->img_width, &vars->img_height);
	vars->walls = mlx_xpm_file_to_image(vars->mlx,
			"./img/walls64.xpm", &vars->img_width, &vars->img_height);
	vars->ring = mlx_xpm_file_to_image(vars->mlx,
			"./img/ring1.xpm", &vars->img_width, &vars->img_height);
	vars->door = mlx_xpm_file_to_image(vars->mlx,
			"./img/closed_door64.xpm", &vars->img_width, &vars->img_height);
	vars->robot = mlx_xpm_file_to_image(vars->mlx,
			"./img/robot.xpm", &vars->img_width, &vars->img_height);
	vars->robot2 = mlx_xpm_file_to_image(vars->mlx,
			"./img/robot2.xpm", &vars->img_width, &vars->img_height);
	vars->sonic = mlx_xpm_file_to_image(vars->mlx,
			"./img/s_wait_d.xpm", &vars->img_width, &vars->img_height);
}

void	print_map(t_vars *vars)
{
	vars->line = 0;
	while (vars->line < vars->height)
	{
		vars->col = 0;
		while (vars->col < vars->width)
		{
			choose_image(vars);
			vars->col++;
		}
		vars->line++;
	}
}

void	choose_image(t_vars *vars)
{
	if (vars->map[vars->line][vars->col] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->walls, 64 * vars->col, 64 * vars->line);
	else if (vars->map[vars->line][vars->col] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->ring, 64 * vars->col, 64 * vars->line);
	else if (vars->map[vars->line][vars->col] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->door, 64 * vars->col, 64 * vars->line);
	else if (vars->map[vars->line][vars->col] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->free_way, 64 * vars->col, 64 * vars->line);
	else if (vars->map[vars->line][vars->col] == '7')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->robot, 64 * vars->col, 64 * vars->line);
	else if (vars->map[vars->line][vars->col] == '8')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->robot2, 64 * vars->col, 64 * vars->line);
	else if (vars->map[vars->line][vars->col] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sonic, 64 * vars->col, 64 * vars->line);
}

void	include_enemy(t_vars *vars)
{
	vars->line = 0;
	while (vars->line < vars->height)
	{
		vars->col = 0;
		while (vars->col < vars->width)
		{
			vars->count_to_robot++;
			if ((vars->count_to_robot % 17 == 0
					|| vars->count_to_robot % 31 == 0)
				&& vars->map[vars->line][vars->col] == '0')
			{
				if (vars->count_to_robot % 2 == 0)
					vars->map[vars->line][vars->col] = '7';
				else
					vars->map[vars->line][vars->col] = '8';
			}
			vars->col++;
		}
		vars->line++;
	}
}

void	render(t_vars *vars)
{
	open_images(vars);
	include_enemy(vars);
	vars->game_over = 0;
	print_map(vars);
	vars->moves = 0;
	print_steps(vars);
}
