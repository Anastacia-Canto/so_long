/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:24:40 by ansilva-          #+#    #+#             */
/*   Updated: 2022/09/13 17:46:10 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Transfer file content to struct*/
void	parse_map(int fd, int index, t_vars *vars)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		parse_map(fd, index + 1, vars);
	else
	{
		vars->height = index;
		vars->map = malloc(sizeof(char *) * (index + 1));
		if (!vars->map)
			return ;
	}
	vars->map[index] = ft_strtrim(line, "\n");
	free (line);
	return ;
}

/*Check if file extension is ".ber" */
int	check_extension(char *map_path)
{
	int		length;
	char	*extension;
	char	*pattern;

	length = (int)ft_strlen(map_path);
	if (length < 5)
		return (0);
	pattern = ".ber";
	extension = ft_substr(map_path, length - 4, length);
	if (ft_strncmp(pattern, extension, 5) != 0)
	{
		free (extension);	
		return (0);
	}
	free (extension);
	return (1);
}

/*Check if the file and the file content fit on requirements*/
int	check_map(char *map_path, int fd, t_vars *vars)
{
	int	index;

	if (fd<0 || !check_extension(map_path))
	{
		ft_printf("\033[1;91mError\nInvalid map path!\n");
		return (0);
	}
	parse_map(fd, 0, vars);
	vars->count_p = 0;
	vars->count_c = 0;
	vars->count_e = 0;
	if (!check_shape(vars) || !check_boundaries_and_content(vars)
		|| vars->count_c == 0 || vars->count_e != 1 || vars->count_p != 1)
	{
		ft_printf("\033[1;91mError\nInvalid map!\n");
		index = 0;
		while (vars->map[index])
			free (vars->map[index++]);
		free (vars->map);
		return (0);
	}
	return (1);
}
