/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:05:03 by welida            #+#    #+#             */
/*   Updated: 2021/03/20 14:05:05 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*p;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	p = (char*)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int		ft_atoi(const char *str)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if ((sign == -1) && \
				((number > 214748364) || (number == 214748364 && *str > '8')))
			error_exit(-3);
		else if ((sign == 1) && \
				((number > 214748364) || (number == 214748364 && *str > '7')))
			error_exit(-3);
		number = number * 10 + *str - '0';
		str++;
	}
	return (sign * number);
}

float	ft_atof(char *str)
{
	float	res;
	int		len;
	int		sign;

	res = ft_atoi(str);
	sign = 1;
	if (res < 0 || *str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str >= '0' && *str <= '9')
		str++;
	len = 1;
	if (*str != '.')
		return (res);
	str++;
	while (*str >= '0' && *str <= '9')
	{
		res += (((int)(*str - '0')) / powf(10, len) * (sign == 1 ? 1 : -1));
		len++;
		str++;
	}
	return (res);
}
