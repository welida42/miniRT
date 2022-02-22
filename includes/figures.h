/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:40:03 by welida            #+#    #+#             */
/*   Updated: 2021/03/21 20:40:06 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

typedef struct		s_sphere
{
	t_vector	center;
	float		radius;
}					t_sphere;

typedef struct		s_plane
{
	t_vector			pos;
	t_vector			normal;
}					t_plane;

typedef struct		s_square
{
	t_vector			center;
	t_vector			normal;
	float				size;
}					t_square;

typedef struct		s_cylinder
{
	t_vector		pos;
	t_vector		normal;
	float			radius;
	float			height;
	t_vector		up;
	t_vector		down;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector			a;
	t_vector			b;
	t_vector			c;
}					t_triangle;

typedef struct		s_cyl_params
{
	float		a;
	float		b;
	float		c;
	float		discr;
	t_vector	n;
	t_vector	m;
	float		dist_1;
	float		dist_2;
	float		res1;
	float		res2;
}					t_cyl_params;

t_sphere			*new_sphere(char *coords, float radius);
t_plane				*new_plane(char *coords, char *normal);
t_triangle			*new_tr(char *a_coords, char *b_coords, char *c_coords);
t_square			*new_square(char *coords, char *normal, float size);
t_cylinder			*new_cyl(char *coords, char *normal, float radius,
					float height);

#endif
