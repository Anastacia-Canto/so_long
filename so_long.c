/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:23:02 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/14 13:16:55 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!check_map(argv[1], fd, &vars))
		return (0);
	ft_printf("\033[1;92mLET'S START!\n");
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,
			vars.width * 64, vars.height * 64, "so_long");
	render(&vars);
	mlx_hook(vars.win, 17, 0, close_window, NULL);
	vars.count_to_robot = 0;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, animation, &vars);
	mlx_loop(vars.mlx);
	close(fd);
	destroy_images(&vars);
	mlx_destroy_window(vars.mlx, vars.win);
	free (vars.map);
	free (vars.win);
	free (vars.mlx);
	return (0);
}
