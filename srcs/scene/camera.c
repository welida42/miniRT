/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:58:41 by welida            #+#    #+#             */
/*   Updated: 2021/02/07 11:04:23 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*new_camera(char *origin, char *direction, float fov)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		error_exit(-1);
	parse_coords(&camera->origin, origin);
	parse_coords(&camera->direction, direction);
	if (check_vector(camera->direction))
		error_exit(-3);
	vec_norm(&camera->direction);
	camera->fov = fov;
	if (camera->fov > 180 || camera->fov < 0)
		error_exit(-3);
	if (camera->fov == 180)
		camera->fov = (float)179.9;
	camera->next = NULL;
	return (camera);
}

t_light		*new_light(char *coords, char *p_color, float intencity)
{
	t_light		*light;

	light = malloc(sizeof(t_light));
	if (!light)
		error_exit(-1);
	parse_coords(&light->pos, coords);
	parse_color(&light->color, p_color);
	light->i = intencity;
	if (light->i < 0 || light->i > 1)
		error_exit(-3);
	light->next = NULL;
	return (light);
}

t_vector	look_at(t_vector cam_dir, t_vector ray)
{
	t_vector	right;
	t_vector	up;
	t_vector	res;

	right = vec_cross(new_vec(0, 1, 0), cam_dir);
	vec_norm(&right);
	up = vec_cross(cam_dir, right);
	vec_norm(&up);
	res.x = -ray.x * right.x + ray.y * up.x + ray.z * cam_dir.x;
	res.y = -ray.x * right.y + ray.y * up.y + ray.z * cam_dir.y;
	res.z = -ray.x * right.z + ray.y * up.z + ray.z * cam_dir.z;
	return (res);
}

t_vector	get_ray_direct(t_vector ray, t_camera *cur_cam)
{
	t_vector direction;

	if (cur_cam->direction.x == 0 && cur_cam->direction.z == 0)
	{
		direction = ray;
		if (cur_cam->direction.y > 0)
		{
			cur_cam->direction.y = (float)1;
			cur_cam->direction.z = (float)-0.000001;
		}
		else
		{
			cur_cam->direction.y = (float)-1;
			cur_cam->direction.z = (float)-0.000001;
		}
		vec_norm(&direction);
	}
	direction = look_at(cur_cam->direction, ray);
	vec_norm(&direction);
	return (direction);
}
