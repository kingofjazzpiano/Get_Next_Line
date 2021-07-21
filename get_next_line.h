#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# define MAX_FD 12000

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
int		get_next_line(int fd, char **line);

#endif
