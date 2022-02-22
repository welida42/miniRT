/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:13:47 by welida            #+#    #+#             */
/*   Updated: 2021/03/22 17:13:50 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_figures(t_figure *figures, void (*func)(void *))
{
	t_figure	*tmp;

	while (figures)
	{
		tmp = figures->next;
		func(figures->ptr);
		free(figures);
		figures = tmp;
	}
}

void	free_lights(t_light *light)
{
	t_light	*tmp;

	while (light)
	{
		tmp = light->next;
		free(light);
		light = tmp;
	}
}

void	free_cameras(t_camera *camera)
{
	t_camera	*tmp;

	while (camera)
	{
		tmp = camera->next;
		free(camera);
		camera = tmp;
	}
}

void	free_scene(t_scene *scene)
{
	if (scene->figures)
		free_figures(scene->figures, &free);
	if (scene->cameras)
		free_cameras(scene->cameras);
	if (scene->lights)
		free_lights(scene->lights);
}
