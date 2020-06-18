/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:09:37 by tturnber          #+#    #+#             */
/*   Updated: 2020/06/09 13:09:42 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strchr(const char *s, int c)
{
	int		size;
	char	v;

	size = 0;
	v = (char)c;
	while (s[size] != '\0')
	{
		if (s[size] == v)
			return (&((char *)s)[size]);
		size++;
	}
	if (s[size] == v)
		return (&((char *)s)[size]);
	return (NULL);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	z;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	dst = malloc(sizeof(char) * ((i + j) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	z = 0;
	while (s1[i] != '\0')
		dst[z++] = s1[i++];
	j = 0;
	while (s2[j] != '\0')
		dst[z++] = s2[j++];
	dst[z] = '\0';
	return (dst);
}

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (start < ft_strlen(s))
	{
		i = 0;
		while (s[start + i] && i < len)
		{
			dst[i] = s[start + i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
