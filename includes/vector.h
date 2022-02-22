/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:46:00 by welida            #+#    #+#             */
/*   Updated: 2021/02/07 10:17:10 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

t_vector		new_vec(float x, float y, float z);
t_vector		vec_sub(t_vector vec1, t_vector vec2);
t_vector		vec_add(t_vector vec1, t_vector vec2);
float			vec_len(t_vector vec);
void			vec_norm(t_vector *vec);
float			vec_dot(t_vector vec1, t_vector vec2);
t_vector		vec_mult(t_vector vec, float factor);
t_vector		vec_cross(t_vector vec1, t_vector vec2);

#endif
