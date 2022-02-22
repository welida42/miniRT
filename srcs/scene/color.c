/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:44:26 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 13:44:31 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	color_new(float r, float g, float b)
{
	t_rgb new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

int		rgb_to_int(t_rgb rgb)
{
	return ((int)rgb.r << 16 | (int)rgb.g << 8 | (int)rgb.b);
}

t_rgb	rgb_light(t_rgb rgb, t_rgb light)
{
	return (color_new(fminf(rgb.r * (light.r / 255), 255),
					fminf(rgb.g * (light.g / 255), 255),
					fminf(rgb.b * (light.b / 255), 255)));
}

t_rgb	rgb_mult(t_rgb rgb, float mult)
{
	return (color_new(fminf(rgb.r * mult, 255), fminf(rgb.g * mult, 255),
			fminf(rgb.b * mult, 255)));
}

t_rgb	rgb_add_rgb(t_rgb rgb, t_rgb add)
{
	return (color_new(fminf(rgb.r + add.r, 255), fminf(rgb.g + add.g, 255),
				fminf(rgb.b + add.b, 255)));
}
