#include <stdlib.h>
#include <stdio.h>

int fibonacci_iter(int n) {
	int n1 = 1, n2 = 1, actual = 1;
	int iter = 0;

	if (n <= 0) return 0;
	else if (n == 1 || n == 2) return 1;

	for (iter = 2; iter < n; iter++) {
		actual = n1 + n2;
		n1 = n2;
		n2 = actual;
	}

	return actual;
}

int fibonacci_rec(int n) {
	if (n <= 2)
		return 1;
	return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}


int main(int argc, char** argv) {
	int fib = 0;

	if (argc < 2) {
		perror("Not enough arguments!");
		return EXIT_FAILURE;
	}

	fib = atoi(argv[1]);

	if (fib <= 0) {
		perror("Number must be greater than 0!");
		return EXIT_FAILURE;
	}

	printf("Fibonacci iter: %d\n", fibonacci_iter(fib));
	printf("Fibonacci rec: %d\n", fibonacci_rec(fib));

	return EXIT_SUCCESS;
}