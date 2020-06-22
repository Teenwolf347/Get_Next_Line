/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:54:53 by tturnber          #+#    #+#             */
/*   Updated: 2020/06/22 17:31:29 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int				ft_checkout(char *line, char *stack)
{
	if (line == NULL && stack != NULL)
	{
		free(stack);
		return (0);
	}
	else if (line != NULL && stack == NULL)
	{
		free(line);
		return (0);
	}
	else if (line == NULL && stack == NULL)
		return (0);
	return (1);
}

static char				*ft_buffer_stack(int i, char *stack, char *buffer)
{
	char				*buffer_stack;

	buffer[i] = '\0';
	buffer_stack = ft_strjoin(stack, buffer);
	free(stack);
	return (buffer_stack);
}

static char				*ft_gnl_read_file(int fd, char **stack)
{
	char				*buffer;
	int					i;

	buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (0);
	}
	if (*stack == NULL)
		*stack = ft_strdup("");
	while (*stack != NULL && !(ft_strchr(*stack, '\n')))
	{
		if ((i = read(fd, buffer, BUFFER_SIZE)) < 0)
		{
			free(buffer);
			return (0);
		}
		*stack = ft_buffer_stack(i, *stack, buffer);
		if (i == 0)
			break ;
	}
	free(buffer);
	return (*stack);
}

int						get_next_line(int fd, char **line)
{
	static char			*stack[1024];
	char				*line_stack;
	char				*copy_stack;

	if (!(line) || !(stack[fd] = ft_gnl_read_file(fd, &stack[fd])))
		return (-1);
	if ((line_stack = ft_strchr(stack[fd], '\n')))
	{
		copy_stack = stack[fd];
		*line = ft_substr(stack[fd], 0, (line_stack - stack[fd]));
		stack[fd] = ft_strdup((stack[fd] + (line_stack - stack[fd])) + 1);
		free(copy_stack);
		if ((ft_checkout(*line, stack[fd])) == 0)
			return (-1);
		return (1);
	}
	else
	{
		*line = ft_strdup(stack[fd]);
		free(stack[fd]);
		stack[fd] = NULL;
		if (*line == NULL)
			return (-1);
		return (0);
	}
}
