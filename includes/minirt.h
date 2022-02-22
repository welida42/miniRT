/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:17:49 by welida            #+#    #+#             */
/*   Updated: 2021/02/07 15:57:35 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# include "../minilibx_mms_20200219/mlx.h"
# include "vector.h"
# include "color.h"
# include "utils.h"
# include "figures.h"
# include "scene.h"
# include "view_plane.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*window;
	t_scene	*scene;
}				t_vars;

void			get_cam(t_scene *scene, t_vars *vars);
t_scene			*parse_file(char *argv);

void			parse_sphere(t_scene *scene, char **split_line);
void			parse_plane(t_scene *scene, char **split_line);
void			parse_tr(t_scene *scene, char **split_line);
void			parse_square(t_scene *scene, char **split_line);
void			parse_cylinder(t_scene *scene, char **split_line);
void			parse_resolution(t_scene *scene, char **split_line);
void			parse_ambient(t_scene *scene, char **split_line);
void			parse_light(t_scene *scene, char **split_line);
void			parse_color(t_rgb *result, char *str);
void			parse_coords(t_vector *result, char *str);
void			parse_camera(t_scene *scene, char **split_line);
void			check_scene(t_scene *scene);
void			check_resolut(t_vars *vars);
void			free_scene(t_scene *scene);
void			*free_splitline(char **array);

#endif
