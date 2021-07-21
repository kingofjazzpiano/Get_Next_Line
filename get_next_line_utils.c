#include "get_next_line"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;
	size_t	k;
	size_t	l;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(new_str = (char*)malloc(sizeof(char) * (len2 + len1 + 1))))
		return (NULL);
	k = 0;
	while (k < len1)
	{
		new_str[k] = s1[k];
		k++;
	}
	free((char*)s1);
	l = 0;
	while (k < (len2 + len1))
		new_str[k++] = s2[l++];
	new_str[k] = 0;
	return (new_str);
}

char		*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	i;

	new_str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	size_t length;

	if (!s)
		return (0);
	length = 0;
	while (*s++)
		length++;
	return (length);
}
