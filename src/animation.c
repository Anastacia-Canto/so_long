/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:14:18 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/15 14:41:14 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_vars *vars)
{
	static int	control;
	long		i;

	move_enemy(vars, control);
	move_rings(vars, control);
	control++;
	if (control >= 4)
		control = 0;
	print_map(vars);
	print_steps_animation(vars);
	i = 0;
	while (i < 126005000)
		i++;
	return (0);
}

void	move_enemy(t_vars *vars, int control)
{
	mlx_destroy_image(vars->mlx, vars->robot);
	mlx_destroy_image(vars->mlx, vars->robot2);
	if (control == 0 || control == 2)
	{
		vars->robot = mlx_xpm_file_to_image(vars->mlx,
				"../img/robot2.xpm", &vars->img_width, &vars->img_height);
		vars->robot2 = mlx_xpm_file_to_image(vars->mlx,
				"../img/robot.xpm", &vars->img_width, &vars->img_height);
	}
	else
	{
		vars->robot = mlx_xpm_file_to_image(vars->mlx,
				"../img/robot.xpm", &vars->img_width, &vars->img_height);
		vars->robot2 = mlx_xpm_file_to_image(vars->mlx,
				"../img/robot2.xpm", &vars->img_width, &vars->img_height);
	}
}

int	move_rings(t_vars *vars, int control)
{
	mlx_destroy_image(vars->mlx, vars->ring);
	if (control == 0)
		vars->ring = mlx_xpm_file_to_image(vars->mlx,
				"../img/ring1.xpm", &vars->img_width, &vars->img_height);
	else if (control == 1)
		vars->ring = mlx_xpm_file_to_image(vars->mlx,
				"../img/ring2.xpm", &vars->img_width, &vars->img_height);
	else if (control == 2)
		vars->ring = mlx_xpm_file_to_image(vars->mlx,
				"../img/ring3.xpm", &vars->img_width, &vars->img_height);
	else
		vars->ring = mlx_xpm_file_to_image(vars->mlx,
				"../img/ring4.xpm", &vars->img_width, &vars->img_height);
	return (0);
}

void	print_steps_animation(t_vars *vars)
{
	char	*message;
	char	*steps;

	if (vars->game_over == 1)
	{
		mlx_string_put(vars->mlx, vars->win, 5, 15, 0xFFC61E07,
			"GAME OVER");
		return ;
	}
	steps = ft_itoa(vars->moves);
	message = "Steps: ";
	message = ft_strjoin_lib(message, steps);
	mlx_string_put(vars->mlx, vars->win, 5, 15, 0xFF1E10E3, message);
	free (steps);
	free (message);
}
