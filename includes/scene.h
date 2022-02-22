/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:06:56 by welida            #+#    #+#             */
/*   Updated: 2021/02/07 11:16:50 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef struct	s_camera
{
	t_vector	origin;
	t_vector	direction;
	float		fov;
	void		*ptr;
	void		*next;
	int			cam_number;
}				t_camera;

typedef struct	s_light
{
	t_vector	pos;
	t_rgb		color;
	float		i;
	void		*ptr;
	void		*next;
}				t_light;

typedef struct	s_figure
{
	char		type;
	void		*ptr;
	void		*next;
	float		dist;
	t_rgb		color;
}				t_figure;

typedef struct	s_scene
{
	int			width;
	int			height;
	t_figure	*figures;
	t_camera	*cameras;
	t_light		*lights;
	float		amb_i;
	t_rgb		amb_color;
	int			cam_count;
	int			cur_cam_num;
	int			save_bmp;
	int			a;
	int			r;
	int			x;
	int			y;
}				t_scene;

typedef struct	s_light_params
{
	t_rgb		amb;
	t_rgb		res;
	t_vector	point;
	t_vector	normal;
	t_vector	light_to_fig;
	float		n_dot_l;
}				t_light_params;

t_scene			*init_scene();
t_vector		get_ray_direct(t_vector ray, t_camera *cur_cam);
t_rgb3			**create_buffer(unsigned int height, unsigned int width);
void			save_bmp(t_scene *scene);
t_camera		*new_camera(char *origin, char *direction, float fov);
t_light			*new_light(char *coords, char *p_color, float intencity);
t_vector		get_normal(t_vector point, t_figure *figure);
t_vector		get_tr_norm(t_figure *figure);
t_vector		get_square_norm(t_figure *figure);
void			cam_numerate(t_camera *camera, t_scene *scene);

float			sphere_intersect(t_figure *figure, t_vector ray,
						t_vector *ray_orig);
float			plane_intersect(t_figure *figure, t_vector ray,
						t_vector *ray_orig);
float			square_intersect(t_figure *figure, t_vector ray,
						t_vector *ray_orig);
float			triangle_intersect(t_figure *figure, t_vector ray,
						t_vector *ray_orig);
float			cylinder_intersect(t_figure *figure, t_vector ray,
						t_vector *ray_orig);

#endif
