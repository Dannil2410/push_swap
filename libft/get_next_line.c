/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:17:34 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/04 16:34:23 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			gnl_verify_line(char **stack, char **line)
{
	char			*tmp;
	char			*str;
	int				i;

	i = 0;
	str = *stack;
	while (str[i] != '\n')
	{
		if (!str[i])
			return (0);
		i++;
	}
	tmp = &str[i];
	*tmp = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp + 1);
	free(str);
	return (1);
}

static	int			gnl_read_file(int fd, char *buf, char **stack, char **line)
{
	int				ret;
	char			*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (*stack)
		{
			tmp = *stack;
			*stack = ft_strjoin(tmp, buf);
			free(tmp);
			tmp = NULL;
		}
		else
			*stack = ft_strdup(buf);
		if (gnl_verify_line(stack, line))
		{
			ret = (ret > 0) ? 1 : ret;
			return (ret);
		}
	}
	return (ret > 0 ? 1 : ret);
}

int					get_next_line(int const fd, char **line)
{
	static char		*stack[10241];
	char			*buf;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= 10241) || (read(fd, stack[fd], 0) < 0)
		|| !(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (stack[fd])
		if (gnl_verify_line(&stack[fd], line))
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		buf[i++] = '\0';
	ret = gnl_read_file(fd, buf, &stack[fd], line);
	free(buf);
	if (ret != 0 || !stack[fd] || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
