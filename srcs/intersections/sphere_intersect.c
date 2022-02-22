/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:24:23 by welida            #+#    #+#             */
/*   Updated: 2021/02/07 15:17:17 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	sphere_intersect(t_figure *figure, t_vector ray, t_vector *ray_orig)
{
	t_vector		to_sphere;
	t_sphere		*p;
	t_cyl_params	param;

	p = (t_sphere *)figure->ptr;
	to_sphere = vec_sub(*ray_orig, p->center);
	param.a = vec_dot(ray, ray);
	param.b = 2 * (vec_dot(to_sphere, ray));
	param.c = vec_dot(to_sphere, to_sphere) -
		(p->radius * p->radius);
	param.discr = (param.b * param.b) - (4 * param.a * param.c);
	if (param.discr < 0)
		return (0);
	param.dist_1 = ((param.b * (-1)) - sqrtf(param.discr)) / (2 * param.a);
	param.dist_2 = ((param.b * (-1)) + sqrtf(param.discr)) / (2 * param.a);
	if (param.dist_1 < 0)
	{
		param.dist_1 = param.dist_2;
		if (param.dist_1 < 0)
			return (0);
	}
	if (param.dist_1 > 0)
		return (param.dist_1);
	return (0);
}
