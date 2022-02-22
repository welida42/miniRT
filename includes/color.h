/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:39:53 by welida            #+#    #+#             */
/*   Updated: 2021/03/21 20:39:56 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "minirt.h"

typedef struct	s_rgb3
{
	unsigned char a[3];
}				t_rgb3;

typedef struct	s_rgb
{
	float	r;
	float	g;
	float	b;
}				t_rgb;

int				rgb_to_int(t_rgb rgb);
t_rgb			int_to_rgb(int color);
t_rgb3			int_to_char(int color);
t_rgb			rgb_mult(t_rgb color, float fact);
t_rgb			rgb_light(t_rgb color, t_rgb light);
t_rgb			color_new(float r, float g, float b);
t_rgb			rgb_add_rgb(t_rgb rgb, t_rgb add);

#endif
