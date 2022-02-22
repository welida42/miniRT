/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:11:44 by welida            #+#    #+#             */
/*   Updated: 2021/03/23 18:41:54 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_resolut(t_vars *vars)
{
	if (vars->scene->width > vars->scene->x)
		vars->scene->width = vars->scene->x;
	if (vars->scene->height > vars->scene->y)
		vars->scene->height = vars->scene->y;
}

void	parse_line2(t_scene *scene, char **split_line)
{
	if ((!ft_strncmp(split_line[0], "sp", 2)) && ft_strlen(split_line[0])
	== 2 && (l_args(split_line) == 4))
		parse_sphere(scene, split_line);
	else if ((!ft_strncmp(split_line[0], "pl", 2)) && ft_strlen(split_line[0])
	== 2 && (l_args(split_line) == 4))
		parse_plane(scene, split_line);
	else if ((!ft_strncmp(split_line[0], "tr", 2)) && ft_strlen(split_line[0])
	== 2 && (l_args(split_line) == 5))
		parse_tr(scene, split_line);
	else if ((!ft_strncmp(split_line[0], "sq", 2)) && ft_strlen(split_line[0])
	== 2 && (l_args(split_line) == 5))
		parse_square(scene, split_line);
	else if ((!ft_strncmp(split_line[0], "cy", 2)) && ft_strlen(split_line[0])
	== 2 && (l_args(split_line) == 6))
		parse_cylinder(scene, split_line);
	else
		error_exit(-3);
}

void	parse_line(t_scene *scene, char **split_line)
{
	if (*split_line == 0)
		return ;
	check_line(split_line);
	if ((!ft_strncmp(split_line[0], "R", 1)) && ft_strlen(split_line[0])
	== 1 && (l_args(split_line) == 3))
		parse_resolution(scene, split_line);
	else if ((!ft_strncmp(split_line[0], "A", 1)) && ft_strlen(split_line[0])
	== 1 && (l_args(split_line) == 3))
		parse_ambient(scene, split_line);
	else if (((!ft_strncmp(split_line[0], "c", 1)) && ft_strlen(split_line[0])
	== 1 && (l_args(split_line)) == 4))
		parse_camera(scene, split_line);
	else if ((!ft_strncmp(split_line[0], "l", 1)) && ft_strlen(split_line[0])
	== 1 && (l_args(split_line) == 4))
		parse_light(scene, split_line);
	else
		parse_line2(scene, split_line);
}

void	*free_splitline(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	return (NULL);
}

t_scene	*parse_file(char *argv)
{
	int		fd;
	int		ret;
	char	*line;
	t_scene	*scene;
	char	**split_line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit(-4);
	scene = init_scene();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		split_line = ft_split(line, ' ');
		parse_line(scene, split_line);
		free_splitline(split_line);
		free(line);
	}
	split_line = ft_split(line, ' ');
	parse_line(scene, split_line);
	free_splitline(split_line);
	free(line);
	check_scene(scene);
	close(fd);
	return (scene);
}
