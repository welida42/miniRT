/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:42:57 by welida            #+#    #+#             */
/*   Updated: 2020/11/12 14:00:06 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		ft_filling_array(char **p, char *s, char c)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			++i;
			++len;
		}
		if (s[i - 1] != c)
			if (!(p[++j] = ft_substr(s, i - len, len)))
			{
				while (j-- >= 0)
					free(p[j]);
				return (0);
			}
	}
	return (1);
}

static size_t	ft_ptr_array(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char	**p;
	size_t	ptr_count;
	int		check;

	if (!s)
		return (NULL);
	ptr_count = ft_ptr_array(s, c);
	p = (char**)malloc(sizeof(char*) * (ptr_count + 1));
	if (!p)
		return (NULL);
	p[ptr_count] = NULL;
	check = ft_filling_array(p, (char*)s, c);
	if (check == 0)
	{
		free(p);
		p = (NULL);
	}
	return (p);
}

void			*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)b;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (b);
}
