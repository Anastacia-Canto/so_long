/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:23:49 by anastacia         #+#    #+#             */
/*   Updated: 2022/09/14 14:56:47 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx_linux/mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		moves;
	int		height;
	int		width;
	int		col;
	int		line;
	int		count_c;
	int		count_p;
	int		count_e;
	int		position[2];
	void	*free_way;
	void	*walls;
	void	*sonic;
	void	*ring;
	void	*robot;
	void	*robot2;
	void	*door;
	int		img_width;
	int		img_height;
	int		count_to_robot;
	int		game_over;
}	t_vars;

enum	e_keys{
	key_W = 119,
	key_S = 115,
	key_A = 97,
	key_D = 100,
	key_ESC = 65307
};

/*Check if map correspond to requirements*/
int		check_map(char *map_path, int fd, t_vars *vars);
int		check_extension(char *map_path);
void	parse_map(int fd, int index, t_vars *vars);
int		check_shape(t_vars *vars);
int		check_boundaries_and_content(t_vars *vars);
void	count_elements(t_vars *vars);
/*Control windom creation and update*/
void	render(t_vars *vars);
void	open_images(t_vars *vars);
void	include_enemy(t_vars *vars);
void	print_map(t_vars *vars);
void	choose_image(t_vars *vars);
void	print_steps(t_vars *vars);
int		close_window(void*anything);
void	destroy_images(t_vars *vars);
/*Control moves*/
int		key_hook(int key, t_vars *vars);
void	move_up(t_vars *vars);
void	move_left(t_vars *vars);
void	move_down(t_vars *vars);
void	move_right(t_vars *vars);
int		actions(char *actual, char *new, t_vars *vars);
void	manage_collectables(t_vars *vars);
/*Control animation*/
int		animation(t_vars *vars);
int		move_rings(t_vars *vars, int control);
void	move_enemy(t_vars *vars, int control);
void	print_steps_animation(t_vars *vars);

#endif