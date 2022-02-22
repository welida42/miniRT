/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:45:45 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 13:45:48 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	int_to_rgb(int color)
{
	t_rgb		result;

	result.r = (float)(color >> 16);
	result.g = (float)(color >> 8);
	result.b = (float)(color >> 0);
	return (result);
}

t_rgb3	int_to_char(int color)
{
	t_rgb3	result;

	result.a[0] = color >> 0;
	result.a[1] = color >> 8;
	result.a[2] = color >> 16;
	return (result);
}
