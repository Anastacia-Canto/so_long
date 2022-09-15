/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:58:50 by ansilva-          #+#    #+#             */
/*   Updated: 2022/09/15 14:40:44 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_vars *vars)
{
	if (key == key_ESC || vars->game_over == 1)
		exit(0);
	if (key == key_W)
		move_up(vars);
	else if (key == key_A)
		move_left(vars);
	else if (key == key_S)
		move_down(vars);
	else if (key == key_D)
		move_right(vars);
	print_map(vars);
	return (0);
}

void	manage_collectables(t_vars *vars)
{
	vars->count_c--;
	if (vars->count_c == 0)
	{
		mlx_destroy_image(vars->mlx, vars->door);
		vars->door = mlx_xpm_file_to_image(vars->mlx,
				"../img/exit.xpm", &vars->img_width, &vars->img_height);
	}
}

int	actions(char *actual, char *new, t_vars *vars)
{
	if (*new == 'C')
		manage_collectables(vars);
	if (*new == 'E' && vars->count_c == 0)
	{
		ft_printf("\033[1;94mCONGRATULATIONS!\n");
		exit(0);
	}
	if (*new == 'E')
		return (0);
	if (*new == '7' || *new == '8')
	{
		mlx_destroy_image(vars->mlx, vars->sonic);
		vars->sonic = mlx_xpm_file_to_image(vars->mlx,
				"../img/s_lose.xpm", &vars->img_width, &vars->img_height);
		vars->game_over = 1;
	}
	*actual = '0';
	*new = 'P';
	vars->moves++;
	print_steps(vars);
	return (1);
}
