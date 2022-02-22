/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:48:55 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 15:48:58 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_tr_edge(t_vector angle_1, t_vector angle_2, t_vector point,
				t_vector normal)
{
	t_vector	edge;
	t_vector	angle_to_point;
	t_vector	c;

	edge = vec_sub(angle_1, angle_2);
	angle_to_point = vec_sub(point, angle_2);
	c = vec_cross(edge, angle_to_point);
	if (vec_dot(normal, c) >= 0)
		return (1);
	return (0);
}

float	triangle_intersect(t_figure *figure, t_vector ray, t_vector *ray_orig)
{
	t_triangle	*tr;
	float		dist;
	float		denom;
	t_vector	normal;
	t_vector	point;

	normal = get_tr_norm(figure);
	tr = (t_triangle *)figure->ptr;
	denom = vec_dot(normal, ray);
	if (denom == 0)
		return (0);
	dist = vec_dot(vec_sub(tr->a, *ray_orig), normal) / denom;
	if (dist <= 0)
		return (0);
	point = vec_add(*ray_orig, vec_mult(ray, dist));
	if (check_tr_edge(tr->b, tr->a, point, normal) &&
		check_tr_edge(tr->a, tr->c, point, normal) &&
		check_tr_edge(tr->c, tr->b, point, normal))
		return (dist);
	return (0);
}
