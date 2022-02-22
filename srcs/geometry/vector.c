/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:46:24 by welida            #+#    #+#             */
/*   Updated: 2021/02/07 10:14:23 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	new_vec(float x, float y, float z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vector	vec_sub(t_vector vec1, t_vector vec2)
{
	t_vector	result;

	result = new_vec(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
	return (result);
}

t_vector	vec_add(t_vector vec1, t_vector vec2)
{
	t_vector	result;

	result = new_vec(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
	return (result);
}

float		vec_len(t_vector vec)
{
	float	result;

	result = sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return (result);
}

void		vec_norm(t_vector *vec)
{
	float	length;

	length = vec_len(*vec);
	vec->x /= length;
	vec->y /= length;
	vec->z /= length;
}
