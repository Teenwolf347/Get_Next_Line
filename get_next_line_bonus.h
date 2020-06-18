/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:19:26 by tturnber          #+#    #+#             */
/*   Updated: 2020/06/09 13:20:01 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif
