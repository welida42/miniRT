/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_plane.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:26:59 by welida            #+#    #+#             */
/*   Updated: 2021/02/07 15:56:42 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H

typedef struct	s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}				t_vplane;

typedef struct	s_tmp
{
	int		mlx_x;
	int		mlx_y;
	float	x_angle;
	float	y_angle;
	int		color;
	float	x_ray;
	float	y_ray;
}				t_tmp;

t_vector		look_at(t_vector cam_dir, t_vector ray);
void			ray_tracing(void *mlx, void *window, t_scene *scene, t_camera
*cur_cam);
void			ray_tracing_bmp(t_rgb3 **buffer, t_scene *scene, t_camera
*cur_cam);
t_vplane		get_view_plane(float width, float height, float fov);
float			get_intersect(t_scene *scene, t_figure *figure, t_vector ray,
						t_vector *ray_orig);
t_figure		*intersect(t_scene *scene, t_vector ray, t_camera *cur_cam);
int				paint(t_scene *scene, t_vector ray, t_camera *cur_cam);
#endif
