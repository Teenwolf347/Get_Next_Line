/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:11:34 by tturnber          #+#    #+#             */
/*   Updated: 2020/06/22 20:06:27 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char				*ft_buffer_stack(int i, char *stack, char *buffer)
{
	char				*buffer_stack;

	buffer[i] = '\0';
	buffer_stack = ft_strjoin(stack, buffer);
	free(stack);
	return (buffer_stack);
}

static char				*ft_gnl_read_file(int fd, char *stack)
{
	char				*buffer;
	int					i;

	if (!(buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
		return (0);
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (0);
	}
	if (stack == NULL)
		stack = ft_strdup("");
	while (stack != NULL && !(ft_strchr(stack, '\n')))
	{
		if ((i = read(fd, buffer, BUFFER_SIZE)) < 0)
		{
			free(buffer);
			return (0);
		}
		stack = ft_buffer_stack(i, stack, buffer);
		if (i == 0)
			break ;
	}
	free(buffer);
	return (stack);
}

int						get_next_line(int fd, char **line)
{
	static char			*stack;
	char				*line_stack;
	char				*copy_stack;

	if (!(line) || !(stack = ft_gnl_read_file(fd, stack)))
		return (-1);
	if ((line_stack = ft_strchr(stack, '\n')))
	{
		copy_stack = stack;
		*line = ft_substr(stack, 0, (line_stack - stack));
		stack = ft_strdup((stack + (line_stack - stack)) + 1);
		free(copy_stack);
		if (*line == NULL || stack == NULL)
			return (-1);
		return (1);
	}
	else
	{
		*line = ft_strdup(stack);
		free(stack);
		stack = NULL;
		if (*line == NULL)
			return (-1);
		return (0);
	}
}
