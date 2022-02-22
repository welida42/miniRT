/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intesect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:53:42 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 15:53:45 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	check_cyl_roots(t_cylinder *cyl, t_vector ray, t_cyl_params *param,
						t_vector *ray_orig)
{
	t_vector	q1;
	t_vector	q2;

	q1 = vec_add(*ray_orig, vec_mult(ray, param->dist_1));
	q2 = vec_add(*ray_orig, vec_mult(ray, param->dist_2));
	if (param->dist_1 > 0)
		if (vec_dot(cyl->normal, vec_sub(q1, cyl->pos)) > 0
			&& vec_dot(cyl->normal, vec_sub(q1, cyl->up)) < 0)
			param->res1 = param->dist_1;
	if (param->dist_2 > 0)
		if (vec_dot(cyl->normal, vec_sub(q2, cyl->pos)) > 0
			&& vec_dot(cyl->normal, vec_sub(q2, cyl->up)) < 0)
			param->res2 = param->dist_2;
	if (param->res1 > 0 && param->res2 > 0)
		return (fminf(param->res1, param->res2));
	else if (param->res1 > 0 && param->res2 == 0)
		return (param->res1);
	else if (param->res2 > 0 && param->res1 == 0)
		return (param->res2);
	return (0);
}

int		get_cyl_roots(t_cylinder *cyl, t_cyl_params *param)
{
	param->a = vec_dot(param->n, param->n);
	param->b = 2 * vec_dot(param->n, param->m);
	param->c = vec_dot(param->m, param->m) - powf(cyl->radius, 2);
	param->discr = powf(param->b, 2) - 4 * param->a * param->c;
	if (param->discr < 0)
		return (0);
	else
	{
		param->dist_1 = (-param->b + sqrtf(param->discr)) / (2 * param->a);
		param->dist_2 = (-param->b - sqrtf(param->discr)) / (2 * param->a);
	}
	if (param->dist_1 > 0 || param->dist_2 > 0)
		return (1);
	return (0);
}

void	init_cyl_params(t_cylinder *cyl, t_vector ray, t_vector *ray_orig,
				t_cyl_params *param)
{
	cyl->up = vec_add(cyl->pos, vec_mult(cyl->normal, cyl->height));
	param->n = vec_sub(ray, vec_mult(cyl->normal, vec_dot(ray, cyl->normal)));
	param->m = vec_sub(vec_sub(*ray_orig, cyl->pos),
					vec_mult(cyl->normal, vec_dot(vec_sub(*ray_orig, cyl->pos),
							cyl->normal)));
	param->res1 = 0;
	param->res2 = 0;
}

float	cylinder_intersect(t_figure *figure, t_vector ray, t_vector *ray_orig)
{
	t_cylinder		*cyl;
	t_cyl_params	param;
	float			dist;

	dist = 0;
	cyl = (t_cylinder *)figure->ptr;
	init_cyl_params(cyl, ray, ray_orig, &param);
	if (get_cyl_roots(cyl, &param))
		dist = check_cyl_roots(cyl, ray, &param, ray_orig);
	return (dist);
}
