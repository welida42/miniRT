/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:53:42 by welida            #+#    #+#             */
/*   Updated: 2021/03/22 16:54:00 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_name(char *name)
{
	int i;

	comma_count(name, 1, 0, 0);
	i = ft_strlen(name);
	if (i > 3)
		if (name[i - 1] == 't' && name[i - 2] == 'r' && name[i - 3] == '.')
			return (0);
	return (1);
}

int		key_hook(int keycode, t_vars *vars)
{
	if (keycode == 124)
		vars->scene->cur_cam_num++;
	else if (keycode == 123)
		vars->scene->cur_cam_num--;
	else if (keycode == 53)
		exit(0);
	get_cam(vars->scene, vars);
	return (0);
}

int		win_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	exit(0);
}

void	ft_save(char **argv, t_vars *vars)
{
	if (ft_strncmp(argv[2], "--save", 6) == 0)
	{
		if (ft_strlen(argv[2]) != 6)
			error_exit(-5);
		save_bmp(vars->scene);
		exit(0);
	}
	else
		error_exit(-5);
}

int		main(int argc, char **argv)
{
	t_vars vars;

	if (argc != 2 && argc != 3)
		error_exit(-2);
	if (check_name(argv[1]))
		error_exit(-5);
	vars.scene = parse_file(argv[1]);
	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &vars.scene->x, &vars.scene->y);
	check_resolut(&vars);
	vars.scene->save_bmp = 0;
	vars.scene->cur_cam_num = 1;
	if (argc == 3)
		ft_save(argv, &vars);
	vars.window = mlx_new_window(vars.mlx, vars.scene->width,
								vars.scene->height, "miniRT");
	mlx_hook(vars.window, 17, 0, win_close, &vars);
	mlx_key_hook(vars.window, key_hook, &vars);
	get_cam(vars.scene, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
