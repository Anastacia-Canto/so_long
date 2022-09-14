/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:21:04 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/14 14:23:34 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Close window when press 'x'*/
int	close_window(void*anything)
{
	(void)anything;
	exit(0);
	return (0);
}

void	destroy_images(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->free_way);
	mlx_destroy_image(vars->mlx, vars->walls);
	mlx_destroy_image(vars->mlx, vars->sonic);
	mlx_destroy_image(vars->mlx, vars->ring);
	mlx_destroy_image(vars->mlx, vars->door);
	mlx_destroy_image(vars->mlx, vars->robot);
	mlx_destroy_image(vars->mlx, vars->robot2);
}

void	print_steps(t_vars *vars)
{
	char	*message;
	char	*steps;

	steps = ft_itoa(vars->moves);
	message = "Steps: ";
	message = ft_strjoin_lib(message, steps);
	mlx_string_put(vars->mlx, vars->win, 5, 15, 0xFF1E10E3, message);
	if (vars->moves > 0)
		ft_printf("steps: %i\n", vars->moves);
	if (vars->game_over == 1)
	{
		mlx_string_put(vars->mlx, vars->win, 5, 15, 0xFFC61E07,
			"GAME OVER");
		ft_printf("\033[1;91mGAME OVER\n");
		free (steps);
		free (message);
		return ;
	}
	free (steps);
	free (message);
}
