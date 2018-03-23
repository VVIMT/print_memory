#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putoctal(short nbr)
{
	if (nbr % 16 >= 0 && nbr % 16 < 10)
		ft_putchar(nbr % 16 + '0');
	else if (nbr % 16 >= 10 && nbr % 16 < 16)
		ft_putchar(nbr % 16 - 10 + 'a');
}

void	print_memory(const void *addr, size_t size)
{
	size_t	index;
	short	*nbr;

	nbr = (short*)addr;
	index = 0;
	while (index < size / sizeof(short))
	{
		ft_putoctal(nbr[index] >> 4);
		ft_putoctal(nbr[index]);
		if (size - index >= 2)
		{
			ft_putoctal(nbr[index] >> 12);
			ft_putoctal(nbr[index] >> 8);
		}
		ft_putchar(' ');
		index++;
		if (index % 8 == 0)
			ft_putchar('\n');
	}
}

int main(void)
{
	int tab[10] = {0, 23, 150, 255, 12, 16, 42, 103};

	print_memory(tab, sizeof(tab));
	return (0);
}
