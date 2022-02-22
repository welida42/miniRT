/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:38:53 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 15:38:57 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	get_plane_norm(t_figure *figure)
{
	t_plane *plane;

	plane = (t_plane *)figure->ptr;
	return (plane->normal);
}

t_vector	get_tr_norm(t_figure *figure)
{
	t_vector	edge1;
	t_vector	edge2;
	t_vector	normal;
	t_triangle	*tr;

	tr = (t_triangle *)figure->ptr;
	edge1 = vec_sub(tr->b, tr->a);
	edge2 = vec_sub(tr->c, tr->a);
	normal = vec_cross(edge1, edge2);
	vec_norm(&normal);
	return (normal);
}

t_vector	get_square_norm(t_figure *figure)
{
	t_square	*square;

	square = (t_square *)figure->ptr;
	return (square->normal);
}

t_vector	get_cy_norm(t_vector point, t_figure *figure)
{
	t_cylinder	*cylinder;
	t_vector	n;
	t_vector	to_cyl;
	t_vector	c_norm;

	cylinder = (t_cylinder *)figure->ptr;
	to_cyl = vec_sub(point, cylinder->pos);
	c_norm = vec_mult(cylinder->normal, vec_dot(cylinder->normal, to_cyl));
	n = vec_sub(to_cyl, c_norm);
	vec_norm(&n);
	return (n);
}

t_vector	get_normal(t_vector point, t_figure *figure)
{
	t_sphere *sphere;
	t_vector n;

	if (figure->type == 'p')
		return (get_plane_norm(figure));
	else if (figure->type == 't')
		return (get_tr_norm(figure));
	else if (figure->type == 'q')
		return (get_square_norm(figure));
	else if (figure->type == 'c')
		return (get_cy_norm(point, figure));
	sphere = (t_sphere *)figure->ptr;
	n = vec_sub(point, sphere->center);
	vec_norm(&n);
	return (n);
}
