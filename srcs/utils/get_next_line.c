/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welida <welida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:41:21 by welida            #+#    #+#             */
/*   Updated: 2020/12/13 18:33:01 by welida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char			*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	p = (char*)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

char			*ft_strjoin(const char *s1, const char *s2)
{
	size_t	sumlen;
	size_t	i;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	sumlen = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(sizeof(char) * (sumlen + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (i < sumlen)
	{
		p[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	p[sumlen] = '\0';
	return (p);
}

char			*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (s == 0)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

int				gnl(char **line, char **st_remainder, char *p_n, int rd)
{
	char	*tmp;

	if (rd < 0)
		return (-1);
	if (p_n)
	{
		*line = ft_substr(*st_remainder, 0, p_n - *st_remainder);
		p_n++;
		tmp = ft_strdup(p_n);
		free(*st_remainder);
		*st_remainder = tmp;
		return (1);
	}
	if (*st_remainder)
	{
		*line = *st_remainder;
		*st_remainder = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*st_remainder;
	char		buf[BUFFER_SIZE + 1];
	int			rd;
	char		*tmp;
	char		*p_n;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while (!(p_n = ft_strchr(st_remainder, '\n')) &&
		(rd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if (!st_remainder)
			tmp = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(st_remainder, buf);
			free(st_remainder);
		}
		st_remainder = tmp;
		tmp = NULL;
	}
	return (gnl(line, &st_remainder, p_n, rd));
}
