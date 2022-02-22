/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:21:26 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 16:21:29 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_resolution(t_scene *scene, char **split_line)
{
	if (scene->r == 1)
		error_exit(-3);
	scene->r = 1;
	scene->width = ft_atoi(split_line[1]);
	scene->height = ft_atoi(split_line[2]);
	if (scene->height <= 0 || scene->width <= 0)
		error_exit(-3);
}

void	parse_ambient(t_scene *scene, char **split_line)
{
	if (scene->a == 1)
		error_exit(-3);
	scene->a = 1;
	parse_color(&scene->amb_color, split_line[2]);
	comma_count(split_line[1], 1, 0, 0);
	scene->amb_i = ft_atof(split_line[1]);
	if (scene->amb_i < 0 || scene->amb_i > 1)
		error_exit(-3);
}

void	parse_light(t_scene *scene, char **split_line)
{
	t_light		*light;
	t_light		*p;

	comma_count(split_line[2], 1, 0, 0);
	light = new_light(split_line[1], split_line[3], ft_atof(split_line[2]));
	p = scene->lights;
	if (scene->lights == NULL)
		scene->lights = light;
	else
	{
		while (p->next)
			p = p->next;
		p->next = light;
	}
}

void	cam_numerate(t_camera *camera, t_scene *scene)
{
	int	i;

	i = 1;
	while (camera)
	{
		camera->cam_number = i;
		i++;
		camera = camera->next;
	}
	scene->cam_count = --i;
}

void	parse_camera(t_scene *scene, char **split_line)
{
	t_camera	*camera;
	t_camera	*p;

	comma_count(split_line[3], 1, 0, 0);
	camera = new_camera(split_line[1], split_line[2], ft_atof(split_line[3]));
	p = scene->cameras;
	if (scene->cameras == NULL)
		scene->cameras = camera;
	else
	{
		while (p->next)
			p = p->next;
		p->next = camera;
	}
	cam_numerate(scene->cameras, scene);
}
