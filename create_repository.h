#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <fcntl.h>

int	write_file_py(char *s);
int	ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *s);
void	install_lib_py(char *str);
void	create_repository_py();

char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dst, char *src, size_t size);

#endif