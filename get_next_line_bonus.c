/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:54:53 by tturnber          #+#    #+#             */
/*   Updated: 2020/06/18 16:24:17 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char				*ft_gnl_read_file(int fd, char **stack)
{
	char				*buffer;
	char				*buffer_stack;
	int					i;

	buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (0);
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (*stack == NULL)
		*stack = ft_strdup("");
	while (*stack != NULL && !(ft_strchr(*stack, '\n')))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (0);
		buffer[i] = '\0';
		buffer_stack = ft_strjoin(*stack, buffer);
		free(*stack);
		*stack = buffer_stack;
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
		if (*line == NULL || stack[fd] == NULL)
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
