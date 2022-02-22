/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:30:42 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 15:30:47 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		vec_dot(t_vector vec1, t_vector vec2)
{
	float result;

	result = ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
	return (result);
}

t_vector	vec_mult(t_vector vec, float factor)
{
	t_vector	result;

	result = new_vec(vec.x * factor, vec.y * factor, vec.z * factor);
	return (result);
}

t_vector	vec_cross(t_vector vec1, t_vector vec2)
{
	t_vector	result;

	result = new_vec((vec1.y * vec2.z) - (vec1.z * vec2.y),
				(vec1.z * vec2.x) - (vec1.x * vec2.z),
				(vec1.x * vec2.y) - (vec1.y * vec2.x));
	return (result);
}
