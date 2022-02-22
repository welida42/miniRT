/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:14:30 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 16:21:14 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_scene *scene, char **split_line)
{
	t_figure	*figure;
	t_figure	*p;
	t_sphere	*sphere;

	figure = malloc(sizeof(t_figure));
	if (figure == 0)
		error_exit(-1);
	comma_count(split_line[2], 1, 0, 0);
	sphere = new_sphere(split_line[1], ft_atof(split_line[2]) / 2);
	figure->ptr = sphere;
	figure->type = 's';
	figure->next = NULL;
	parse_color(&figure->color, split_line[3]);
	p = scene->figures;
	if (scene->figures == NULL)
		scene->figures = figure;
	else
	{
		while (p->next)
			p = p->next;
		p->next = figure;
	}
}

void	parse_plane(t_scene *scene, char **split_line)
{
	t_figure	*figure;
	t_figure	*p;
	t_plane		*plane;

	figure = malloc(sizeof(t_figure));
	if (figure == 0)
		error_exit(-1);
	plane = new_plane(split_line[1], split_line[2]);
	figure->ptr = plane;
	figure->type = 'p';
	figure->next = NULL;
	parse_color(&figure->color, split_line[3]);
	p = scene->figures;
	if (scene->figures == NULL)
		scene->figures = figure;
	else
	{
		while (p->next)
			p = p->next;
		p->next = figure;
	}
}

void	parse_tr(t_scene *scene, char **split_line)
{
	t_figure	*figure;
	t_figure	*p;
	t_triangle	*tr;

	figure = malloc(sizeof(t_figure));
	if (figure == 0)
		error_exit(-1);
	tr = new_tr(split_line[1], split_line[2], split_line[3]);
	figure->ptr = tr;
	figure->type = 't';
	figure->next = NULL;
	parse_color(&figure->color, split_line[4]);
	p = scene->figures;
	if (scene->figures == NULL)
		scene->figures = figure;
	else
	{
		while (p->next)
			p = p->next;
		p->next = figure;
	}
}

void	parse_square(t_scene *scene, char **split_line)
{
	t_figure	*figure;
	t_figure	*p;
	t_square	*square;

	figure = malloc(sizeof(t_figure));
	if (!figure)
		error_exit(-1);
	comma_count(split_line[3], 1, 0, 0);
	square = new_square(split_line[1], split_line[2], ft_atof(split_line[3]));
	figure->ptr = square;
	figure->type = 'q';
	figure->next = NULL;
	parse_color(&figure->color, split_line[4]);
	if (check_color(figure->color))
		error_exit(-3);
	p = scene->figures;
	if (scene->figures == NULL)
		scene->figures = figure;
	else
	{
		while (p->next)
			p = p->next;
		p->next = figure;
	}
}

void	parse_cylinder(t_scene *scene, char **split_line)
{
	t_figure	*figure;
	t_figure	*p;
	t_cylinder	*cylinder;

	figure = malloc(sizeof(t_figure));
	if (figure == 0)
		error_exit(-1);
	comma_count(split_line[3], 1, 0, 0);
	comma_count(split_line[4], 1, 0, 0);
	cylinder = new_cyl(split_line[1], split_line[2],
		ft_atof(split_line[3]) / 2, ft_atof(split_line[4]));
	figure->ptr = cylinder;
	figure->type = 'c';
	figure->next = NULL;
	parse_color(&figure->color, split_line[5]);
	p = scene->figures;
	if (scene->figures == NULL)
		scene->figures = figure;
	else
	{
		while (p->next)
			p = p->next;
		p->next = figure;
	}
}
