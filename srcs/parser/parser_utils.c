/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:57:56 by welida            #+#    #+#             */
/*   Updated: 2021/03/21 18:57:58 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_coords(t_vector *result, char *str)
{
	char	**coords;

	coords = ft_split(str, ',');
	if (l_args(coords) != 3)
		error_exit(-3);
	comma_count(str, 3, 2, 3);
	result->x = ft_atof(coords[0]);
	result->y = ft_atof(coords[1]);
	result->z = ft_atof(coords[2]);
	free_splitline(coords);
}

void	comma_count(char *str, int dot_max, int coma_max, int minus_max)
{
	int	comma;
	int	dot;
	int	minus;

	comma = 0;
	dot = 0;
	minus = 0;
	while (*str)
	{
		if (*str == '.')
			dot++;
		if (*str == ',')
			comma++;
		if (*str == '-')
			minus++;
		str++;
	}
	if (dot > dot_max || comma > coma_max || minus > minus_max)
		error_exit(-3);
}

void	parse_color(t_rgb *result, char *str)
{
	char	**color;

	color = ft_split(str, ',');
	if (l_args(color) != 3)
		error_exit(-3);
	comma_count(str, 3, 2, 3);
	result->r = ft_atof(color[0]);
	result->g = ft_atof(color[1]);
	result->b = ft_atof(color[2]);
	if (check_color(*result))
		error_exit(-3);
	free_splitline(color);
}

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (scene == 0)
		error_exit(-1);
	scene->width = 0;
	scene->height = 0;
	scene->amb_i = -1;
	scene->amb_color.r = 0;
	scene->amb_color.g = 0;
	scene->amb_color.b = 0;
	scene->cameras = NULL;
	scene->lights = NULL;
	scene->figures = NULL;
	scene->a = 0;
	scene->r = 0;
	return (scene);
}

void	check_scene(t_scene *scene)
{
	if (scene->r == 0 || scene->a == 0)
		error_exit(-3);
	if (scene->cameras == NULL)
		error_exit(-3);
	if (scene->width <= 0 || scene->height <= 0)
		error_exit(-3);
}
