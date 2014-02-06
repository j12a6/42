#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*s;
	char	*p;
	char	*m;

	s = malloc(sizeof(char) * 2);
	p = s;
	free((void *)p);
	s = NULL;
	printf("%p et %p et %p\n", s, p, m);
	return (0);
}
