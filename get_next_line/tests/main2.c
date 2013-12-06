#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	int		i;

	i = 0;
	while (i < 2000000)
	{
		ft_putchar('c');
		i++;
		if (i % 1000000 == 0)
			ft_putchar ('\n');
	}
	ft_putchar('a');
	return (0);
}

