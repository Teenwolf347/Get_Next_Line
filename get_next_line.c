/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:11:34 by tturnber          #+#    #+#             */
/*   Updated: 2020/06/09 14:59:31 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_gnl_read_file(int fd, char *stack)
{
	char			*buffer;
	char			*buffer_stack;
	int				i;

	buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (0);
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (stack == NULL)
		stack = ft_strdup("");
	while (!(ft_strchr(stack, '\n')))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (0);
		buffer[i] = '\0';
		buffer_stack = ft_strjoin(stack, buffer);
		free(stack);
		stack = buffer_stack;
		if (i == 0)
			break ;
	}
	free(buffer);
	return (stack);
}

int					get_next_line(int fd, char **line)
{
	static char		*stack;
	char			*line_stack;
	char			*copy_stack;

	stack = ft_gnl_read_file(fd, stack);
	if (!(line) || !(stack))
		return (-1);
	line_stack = ft_strchr(stack, '\n');
	if (line_stack)
	{
		copy_stack = stack;
		*line = ft_substr(stack, 0, (line_stack - stack));
		stack = ft_strdup((stack + (line_stack - stack)) + 1);
		free(copy_stack);
		return (1);
	}
	else
	{
		*line = ft_strdup(stack);
		free(stack);
		stack = NULL;
		return (0);
	}
}
