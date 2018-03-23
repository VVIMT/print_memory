#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthexa(short nbr)
{
	if (nbr % 16 >= 0 && nbr % 16 < 10)
		ft_putchar(nbr % 16 + '0');
	else if (nbr % 16 >= 10 && nbr % 16 < 16)
		ft_putchar(nbr % 16 - 10 + 'a');
}

void	print_dots(size_t index, short *nbr, size_t size)
{
	while (index < size)
	{
		if (nbr[index] >= 32 && nbr[index] <= 126)
			ft_putchar(nbr[index]);
		else
			ft_putchar('.');
		if ((nbr[index] >> 8) >= 32 && (nbr[index] >> 8) <= 126)
			ft_putchar(nbr[index] >> 8);
		else
			ft_putchar('.');
		index++;
	}
	ft_putchar('\n');
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;
	size_t	index;
	short	*nbr;

	nbr = (short*)addr;
	index = 0;
	while (index < size / sizeof(short))
	{
		ft_puthexa(nbr[index] >> 4);
		ft_puthexa(nbr[index]);
		if (size - index >= 2)
		{
			ft_puthexa(nbr[index] >> 12);
			ft_puthexa(nbr[index] >> 8);
		}
		ft_putchar(' ');
		index++;
		if (index % 8 == 0)
			print_dots(index - 8, nbr, index);
	}
	i = index;
	while (i % 8 != 0)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		ft_putchar(' ');
		ft_putchar(' ');
		ft_putchar(' ');
		i++;
	}
	print_dots(index - (index % 8), nbr, index);
}

int		main(void)
{
	int tab[8] = {0, 23, 150, 255, 12, 16, 42, 103};

	print_memory(tab, sizeof(tab));
	return (0);
}
