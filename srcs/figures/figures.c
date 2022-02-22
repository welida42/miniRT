/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:21:11 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 15:21:13 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*new_sphere(char *coords, float radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		error_exit(-1);
	parse_coords(&sphere->center, coords);
	sphere->radius = radius;
	if (sphere->radius <= 0)
		error_exit(-3);
	return (sphere);
}

t_plane		*new_plane(char *coords, char *normal)
{
	t_plane *plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		error_exit(-1);
	parse_coords(&plane->pos, coords);
	parse_coords(&plane->normal, normal);
	if (check_vector(plane->normal))
		error_exit(-3);
	vec_norm(&plane->normal);
	return (plane);
}

t_triangle	*new_tr(char *a_coords, char *b_coords, char *c_coords)
{
	t_triangle	*tr;

	tr = malloc(sizeof(t_triangle));
	if (!tr)
		error_exit(-1);
	parse_coords(&tr->a, a_coords);
	parse_coords(&tr->b, b_coords);
	parse_coords(&tr->c, c_coords);
	return (tr);
}

t_square	*new_square(char *coords, char *normal, float size)
{
	t_square *square;

	square = malloc(sizeof(t_square));
	if (!square)
		error_exit(-1);
	parse_coords(&square->center, coords);
	parse_coords(&square->normal, normal);
	if (check_vector(square->normal))
		error_exit(-3);
	square->size = size;
	if (square->size <= 0)
		error_exit(-3);
	vec_norm(&square->normal);
	return (square);
}

t_cylinder	*new_cyl(char *coords, char *normal, float radius, float height)
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		error_exit(-1);
	parse_coords(&cylinder->pos, coords);
	parse_coords(&cylinder->normal, normal);
	if (check_vector(cylinder->normal))
		error_exit(-3);
	cylinder->radius = radius;
	cylinder->height = height;
	if (cylinder->height <= 0 || cylinder->radius <= 0)
		error_exit(-3);
	vec_norm(&cylinder->normal);
	return (cylinder);
}
