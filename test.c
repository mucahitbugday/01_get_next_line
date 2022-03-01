#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	int		len;
	char	*ptr;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len = strlen(s1) + strlen(s2);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	//free (s1);
	s1 = NULL;
    return (ptr);
}

int main()
{
    char *s1 = "mücahit";
    char *s2 = "ca";
    
    printf("%s",ft_strjoin(s1,s2));
    return 0;
}