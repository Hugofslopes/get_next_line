#include "gnl.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		if(*str++ == '\n')
			return (i);
	}
	return (i);
}

int	find_newline(char *strgs)
{
	static size_t i = 0;
	
	if (!strgs)
		return (0);
	while (strgs[i] || i < BUFFER_SIZE)
	{
		if (strgs[i++] == '\n')
			return (1);
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*s;
	char			*d;	

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (d == s || n == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

char *ft_realloc(char *ptr, size_t new_size) 
{
	char	*new_ptr;
	size_t	old_size;
	size_t copy_size;

    if (new_size == 0) 
        return (free(ptr),NULL);
    if (ptr == NULL) 
        return (ft_calloc(new_size + 1 , 1));
    new_ptr = ft_calloc(new_size + 1 , sizeof(char));
    if (new_ptr == NULL) 
        return NULL; 
    old_size = ft_strlen(ptr); 
    if (new_size < old_size) 
        copy_size = new_size;
    else
        copy_size = old_size;
    ft_memmove(new_ptr, ptr, copy_size);
    free(ptr);
    return (new_ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_bytes;
	size_t	i;
	char	*str;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_bytes = nmemb * size;
	if ((total_bytes / size) != nmemb)
		return (NULL);
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
	i = 0;
	str = (char *)ptr;
	while (i < total_bytes)
		str[i++] = '\0';
	return (ptr);
}