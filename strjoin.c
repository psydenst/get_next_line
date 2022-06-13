#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	a;
	size_t	b;

	if (s1 == 0)
		return (s2);
	p = malloc((ft_strlen(s1) + ft_strlen(s2)) * (sizeof(char *)));
	if (p == 0)
		return (NULL);
	a = 0;
	b = 0;

	while (a < ft_strlen(s1))
	{
		p[a] = s1[a];
		a++;
	}
	while (a < ft_strlen(s1) + ft_strlen(s2))
	{
		p[a] = s2[b];
		a++;
		b++;
	}
	p[a] = '\0';
	return (p);
}

#include <stdio.h>
int main()
{
    char s1[] = NULL;
    char s2[] = "Teste";
    printf("%s\n", ft_strjoin(s1, s2));
}