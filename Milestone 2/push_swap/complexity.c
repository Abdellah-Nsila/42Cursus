
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_insertion_sort(int *arr, int arr_size)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	while (i < arr_size)
	{
		printf("%d\n", arr[i]);
		while (i < arr_size)
		{
			printf("%d\n", arr[i]);
			i++;
		}
		i++;
	}
}

int main()
{
	int arr[] = {4,9,2,0,3,6};
	int arr_size = sizeof(arr) / sizeof(int);

	printf("||---------------------------- ft_insertion_sort ----------------------------||\n\n");
	ft_insertion_sort(arr, arr_size);
	printf("\n||---------------------------------------------------------------------------||\n");
}
