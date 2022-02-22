/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:43:37 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 15:43:40 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	get_intersect(t_scene *scene, t_figure *figure, t_vector ray,
					t_vector *ray_orig)
{
	(void)scene;
	if (figure->type == 's')
		return (sphere_intersect(figure, ray, ray_orig));
	else if (figure->type == 'p')
		return (plane_intersect(figure, ray, ray_orig));
	else if (figure->type == 't')
		return (triangle_intersect(figure, ray, ray_orig));
	else if (figure->type == 'q')
		return (square_intersect(figure, ray, ray_orig));
	else if (figure->type == 'c')
		return (cylinder_intersect(figure, ray, ray_orig));
	else
		return (0);
}
