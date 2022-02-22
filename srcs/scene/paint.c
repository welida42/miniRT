/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:35:03 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 13:35:13 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure		*intersect(t_scene *scene, t_vector ray, t_camera *cur_cam)
{
	t_figure	*cur_figure;
	float		min_dist;
	float		dist;
	t_figure	*closest_figure;

	min_dist = 1000000000.0f;
	closest_figure = NULL;
	cur_figure = scene->figures;
	while (cur_figure)
	{
		if ((dist = get_intersect(scene, cur_figure, ray,
							&cur_cam->origin)) && dist < min_dist)
		{
			min_dist = dist;
			closest_figure = cur_figure;
		}
		cur_figure = cur_figure->next;
	}
	if (closest_figure != NULL)
		closest_figure->dist = min_dist;
	return (closest_figure);
}

float			shadow(t_scene *scene, t_figure *cl_fig, t_light *cur_light,
			t_vector point)
{
	t_figure	*figure;
	float		dist;
	float		res;
	t_vector	light_to_fig;

	(void)cl_fig;
	light_to_fig = vec_sub(cur_light->pos, point);
	vec_norm(&light_to_fig);
	figure = scene->figures;
	dist = vec_len(vec_sub(cur_light->pos, point));
	while (figure)
	{
		res = get_intersect(scene, figure, light_to_fig, &point);
		if (res < dist && res > 0)
			return (res);
		figure = figure->next;
	}
	return (0);
}

float			get_ndotl(t_vector light, t_vector normal)
{
	float n_dot_l;

	n_dot_l = vec_dot(light, normal);
	if (n_dot_l <= 0)
		return (0);
	return (n_dot_l);
}

t_rgb			all_light(t_scene *scene, t_figure *cl_fig, t_vector ray,
				t_camera *cur_cam)
{
	t_light			*cur_light;
	t_light_params	l;

	l.amb = rgb_light(cl_fig->color, rgb_mult(scene->amb_color, scene->amb_i));
	l.point = vec_add(cur_cam->origin, vec_mult(ray, cl_fig->dist));
	l.normal = get_normal(l.point, cl_fig);
	if (vec_dot(ray, l.normal) > 0)
		l.normal = vec_mult(l.normal, -1);
	cur_light = scene->lights;
	while (cur_light)
	{
		l.light_to_fig = vec_sub(cur_light->pos, l.point);
		vec_norm(&l.light_to_fig);
		l.point = vec_add(l.point, vec_mult(l.normal, 0.0001f));
		if (shadow(scene, cl_fig, cur_light, l.point))
		{
			cur_light = cur_light->next;
			continue;
		}
		l.n_dot_l = get_ndotl(l.light_to_fig, l.normal);
		l.res = rgb_mult(cur_light->color, cur_light->i * l.n_dot_l);
		l.amb = rgb_add_rgb(l.amb, rgb_light(cl_fig->color, l.res));
		cur_light = cur_light->next;
	}
	return (l.amb);
}

int				paint(t_scene *scene, t_vector ray, t_camera *cur_cam)
{
	t_rgb		res_color;
	t_figure	*cl_fig;

	res_color = color_new(0, 0, 0);
	cl_fig = intersect(scene, ray, cur_cam);
	if (cl_fig)
		res_color = all_light(scene, cl_fig, ray, cur_cam);
	return (rgb_to_int(res_color));
}
