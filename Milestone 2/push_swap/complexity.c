
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// ft_swap(&min, &arr[j]);

void	ft_print_arr(int *arr, int arr_size)
{
	size_t	i;

	i = 0;
	printf("{ ");
	while (i < arr_size)
	{
		if (i == arr_size - 1)
			printf("%d", arr[i]);
		else
			printf("%d, ", arr[i]);
		i++;
	}
	printf("}\n");
}

// Function to find the maximum value in the array
int ft_find_max(int *arr, int arr_size)
{
	int i, max = arr[0];
	for (i = 1; i < arr_size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

// Function to print the array in a vertical bar chart format
void ft_print_graph_arr(int *arr, int arr_size)
{
	int i, j;
	int max = ft_find_max(arr, arr_size);

	// Print row by row from top (max) to bottom (1)
	for (i = max; i > 0; i--)
	{
		for (j = 0; j < arr_size; j++)
		{
			if (arr[j] >= i)  // Print '*' if the current value is >= the row level
				printf("* ");
			else
				printf("  "); // Print space for alignment
		}
		printf("\n");
	}

	// Print the base (numbers at the bottom)
	for (i = 0; i < arr_size; i++)
		printf("--");
	printf("\n");

	for (i = 0; i < arr_size; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}

int	ft_insertion_sort(int *arr, int arr_size)
{
	
	int	i;
	int	j;
	int	min;

	// {4 ,9 ,2 ,0 ,3 ,6}
	i = 1;
	while (i < arr_size)
	{
		j = i - 1;
		min = arr[i];
		while ((j >= 0) && (arr[j] > min))
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = min;
		i++;
		ft_print_graph_arr(arr, arr_size);
	}
}


int main()
{
	// int arr[] = {13, 2, 1, 3, 0, 10,5, 4, 9, 12, 11, 8, 7, 6};
	// int arr[] = {3,3,3,13,13,13,3,3,13,13,13,3,3,3};
	int arr[] = {
		{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
		{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
		{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
		{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
		{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},

	};
	int arr_size = sizeof(arr) / sizeof(int);

	printf("||---------------------------- ft_insertion_sort ----------------------------||\n\n");
	// ft_swap(&arr[0], &arr[1]);
	ft_insertion_sort(arr, arr_size);
	ft_print_arr(arr, arr_size);
	printf("\n||---------------------------------------------------------------------------||\n");
}
