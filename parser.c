#include "push_swap.h"

void	print_error_message(int	*array)
{
	if (array != NULL)
		free(array);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	check_non_digits(int i, long long *nbr, const char *str, int *array)
{
	int	digits;

	digits = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			print_error_message(array);
		(*nbr) = (*nbr) * 10 + (int)(str[i] - 48);
		i++;
		digits++;
	}
	if (digits > 10 || digits == 0)
		print_error_message(array);
}

long long int	ft_atoll(const char *str, int *array)
{
	int			i;
	int			sign;
	long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	check_non_digits(i, &nbr, str, array);
	nbr *= sign;
	return (nbr);
}

void	check_duplicates(int *array, int nbr, int index)
{
	int	k;

	k = 0;
	while (k < index)
	{
		if (array[k] == nbr)
			print_error_message(array);
		k++;
	}
	array[index] = nbr;
}

int	*parse(int argc, char **argv)
{
	int			i;
	int			*array;
	long long	nbr;

	array = malloc((argc - 1) * sizeof(*array));
	if (array == NULL)
		print_error_message(array);
	i = 1;
	while (i < argc)
	{
		nbr = ft_atoll(argv[i], array);
		if (nbr > INT_MAX || nbr < INT_MIN)
			print_error_message(array);
		check_duplicates(array, (int) nbr, i - 1);
		i++;
	}
	return (array);
}
