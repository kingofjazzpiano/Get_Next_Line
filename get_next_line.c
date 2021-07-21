#include "get_next_line.h"

static int			my_free(int i, char **ptr1, char **ptr2)
{
	if (*ptr1 == NULL)
		return (-1);
	free(*ptr1);
	*ptr1 = NULL;
	ptr1 = NULL;
	if (i == 2)
	{
		if (*ptr2 == NULL)
			return (-1);
		free(*ptr2);
		*ptr2 = NULL;
		ptr2 = NULL;
	}
	return (-1);
}

static int			next_string(char **remainder, char **line, char *ptr_to_n)
{
	char			*tmp;

	if (!(*line = ft_strdup(*remainder)))
		return (my_free(1, remainder, NULL));
	if (*ptr_to_n == 0)
	{
		my_free(1, remainder, NULL);
		return (1);
	}
	tmp = ft_strdup(ptr_to_n);
	free(*remainder);
	*remainder = tmp;
	return (1);
}

static int			final_string(char **remainder, char **line, char **buffer)
{
	if (*remainder && !(*line = ft_strjoin(*line, *remainder)))
		return (my_free(2, buffer, remainder));
	my_free(2, buffer, remainder);
	return (0);
}

static int			get_string(char **remainder, char **line, int fd)
{
	char			*ptr_to_n;
	char			*buffer;
	ssize_t			bytes_was_read;

	if (!(buffer = (char*)(malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((bytes_was_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_was_read] = 0;
		if (!(*remainder = ft_strjoin(*remainder, buffer)))
			return (my_free(2, &buffer, remainder));
		if ((ptr_to_n = ft_strchr(*remainder, '\n')))
		{
			free(buffer);
			*ptr_to_n = 0;
			ptr_to_n++;
			return (next_string(remainder, line, ptr_to_n));
		}
	}
	if (!(*line = ft_strdup("")))
		return (my_free(2, remainder, &buffer));
	return (final_string(remainder, line, &buffer));
}

int					get_next_line(int fd, char **line)
{
	char			*ptr_to_n;
	static char		*remainder[MAX_FD];

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1
	|| fd < 0 || fd > MAX_FD || !line)
		return (-1);
	ptr_to_n = NULL;
	if (remainder[fd])
	{
		if ((ptr_to_n = ft_strchr(remainder[fd], '\n')))
		{
			*ptr_to_n = 0;
			ptr_to_n++;
			return (next_string(remainder + fd, line, ptr_to_n));
		}
	}
	return (get_string(remainder + fd, line, fd));
}
