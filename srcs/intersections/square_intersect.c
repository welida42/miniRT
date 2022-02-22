/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:46:38 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 15:46:41 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	plane_intersect(t_figure *figure, t_vector ray, t_vector *ray_orig)
{
	float		denom;
	float		dist;
	t_plane		*pl;
	t_vector	x;

	dist = 0;
	pl = (t_plane *)figure->ptr;
	x = vec_sub(pl->pos, *ray_orig);
	denom = vec_dot(pl->normal, ray);
	if (denom != 0)
		dist = (vec_dot(x, pl->normal) / denom);
	if (dist > 0)
		return (dist);
	return (0);
}

int		check_sq_edge(t_square *sq, t_vector point)
{
	float x;
	float y;
	float z;

	x = point.x - sq->center.x;
	y = point.y - sq->center.y;
	z = point.z - sq->center.z;
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (z < 0)
		z *= -1;
	if ((x <= sq->size / 2) && (y <= sq->size / 2) && (z <= sq->size / 2))
		return (1);
	return (0);
}

float	square_intersect(t_figure *figure, t_vector ray, t_vector *ray_orig)
{
	t_square	*sq;
	float		dist;
	float		denom;
	t_vector	normal;
	t_vector	point;

	normal = get_square_norm(figure);
	sq = (t_square *)figure->ptr;
	denom = vec_dot(normal, ray);
	if (denom == 0)
		return (0);
	dist = vec_dot(vec_sub(sq->center, *ray_orig), normal) / denom;
	if (dist <= 0)
		return (0);
	point = vec_add(*ray_orig, vec_mult(ray, dist));
	if (check_sq_edge(sq, point))
		return (dist);
	return (0);
}
