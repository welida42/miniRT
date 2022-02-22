/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:20:38 by welida            #+#    #+#             */
/*   Updated: 2021/02/10 10:47:53 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vplane		get_view_plane(float width, float height, float fov)
{
	t_vplane	vplane;
	float		aspect_ratio;

	aspect_ratio = width / height;
	vplane.width = tanf(fov / 2 * ((float)M_PI / 180));
	vplane.width *= 2;
	vplane.height = vplane.width / aspect_ratio;
	vplane.x_pixel = vplane.width / width;
	vplane.y_pixel = vplane.height / height;
	return (vplane);
}

t_tmp			init_tmp(t_tmp *tmp, t_scene *scene)
{
	(void)scene;
	tmp->mlx_y = 0;
	tmp->y_angle = ((float)scene->height / 2);
	return (*tmp);
}

void			ray_tracing_bmp(t_rgb3 **buffer, t_scene *scene,
					t_camera *cur_cam)
{
	t_vector	ray;
	t_vplane	vplane;
	t_tmp		tmp;

	tmp = init_tmp(&tmp, scene);
	vplane = get_view_plane((float)scene->width, scene->height, cur_cam->fov);
	while (tmp.y_angle > ((float)scene->height / 2) * (-1))
	{
		tmp.y_ray = tmp.y_angle * vplane.y_pixel;
		tmp.x_angle = ((float)scene->width / 2) * (-1);
		tmp.mlx_x = 0;
		while (tmp.x_angle < (float)scene->width / 2)
		{
			tmp.x_ray = tmp.x_angle * vplane.x_pixel;
			ray = new_vec(tmp.x_ray, tmp.y_ray, 1);
			vec_norm(&ray);
			ray = get_ray_direct(ray, cur_cam);
			tmp.color = paint(scene, ray, cur_cam);
			buffer[tmp.mlx_y][tmp.mlx_x] = int_to_char(tmp.color);
			tmp.x_angle++;
			tmp.mlx_x++;
		}
		tmp.y_angle--;
		tmp.mlx_y++;
	}
}

void			ray_tracing(void *mlx, void *window, t_scene *scene,
				t_camera *cur_cam)
{
	t_vector	ray;
	t_vplane	vplane;
	t_tmp		tmp;

	tmp = init_tmp(&tmp, scene);
	vplane = get_view_plane((float)scene->width, scene->height, cur_cam->fov);
	while (tmp.y_angle > ((float)scene->height / 2) * (-1))
	{
		tmp.y_ray = tmp.y_angle * vplane.y_pixel;
		tmp.x_angle = ((float)scene->width / 2) * (-1);
		tmp.mlx_x = 0;
		while (tmp.x_angle < (float)scene->width / 2)
		{
			tmp.x_ray = tmp.x_angle * vplane.x_pixel;
			ray = new_vec(tmp.x_ray, tmp.y_ray, 1);
			vec_norm(&ray);
			ray = get_ray_direct(ray, cur_cam);
			tmp.color = paint(scene, ray, cur_cam);
			mlx_pixel_put(mlx, window, tmp.mlx_x, tmp.mlx_y, tmp.color);
			tmp.x_angle++;
			tmp.mlx_x++;
		}
		tmp.y_angle--;
		tmp.mlx_y++;
	}
}

void			get_cam(t_scene *scene, t_vars *vars)
{
	t_camera	*cur_cam;
	int			i;

	if (scene->cur_cam_num == scene->cam_count + 1)
		scene->cur_cam_num = 1;
	else if (scene->cur_cam_num == 0)
		scene->cur_cam_num = scene->cam_count;
	i = 1;
	cur_cam = scene->cameras;
	while (i < scene->cur_cam_num && cur_cam != NULL)
	{
		i++;
		cur_cam = cur_cam->next;
	}
	ray_tracing(vars->mlx, vars->window, scene, cur_cam);
}
