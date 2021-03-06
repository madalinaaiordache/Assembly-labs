#include <stdio.h>
#include <stdlib.h>

void print_binary(int number, int nr_bits)
{
	int i;
	char *bits;

	bits = malloc(sizeof(char) * nr_bits);

	for (i = 0; i < nr_bits; ++i) {
		*(bits + i) = 1 & number;
		number >>= 1;
	}

	printf("0b");
	for (i = nr_bits - 1; i >= 0; --i) {
		printf("%d", *(bits + i));
	}
	printf("\n");

	free(bits);
}

void check_parity(int *numbers, int n)
{
	int i, curr_nr;

	for (i = 0; i < n; ++i) {
		curr_nr = *(numbers + i);
		printf("%5d: ", curr_nr);
		if (curr_nr & 1)
			printf("0x%08X\n", curr_nr);
		else
			print_binary(curr_nr, 8);
	}
}

int main()
{
	int *numbers, i, *n;

	n = malloc(sizeof(int));

	printf("Size of array: "); scanf("%d", n);

	numbers = malloc(sizeof(int) * (*n));

	for (i = 0; i < *n; ++i) {
		printf("Number %d: ", i + 1);
		scanf("%d", numbers + i);
	}

	check_parity(numbers, *n);

	// free memory
	free(n);
	free(numbers);

	return 0;
}
