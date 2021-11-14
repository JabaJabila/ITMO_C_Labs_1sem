#include <stdio.h>
#define LEN_ARRAY 7


int main() {
	int array[LEN_ARRAY] = {10, 20, 30, 40, 50, 60, 70};
	printf("Task 1: [");
	for (int i = 0; i <= LEN_ARRAY - 1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d]\n", array[LEN_ARRAY - 1]);

	int matrix1[2][2] = {{1, 2}, {3, 4}};
	int matrix2[2][2] = {{1, 0}, {0, 1}};
	int matrix_res[2][2];
	matrix_res[0][0] = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0];
	matrix_res[0][1] = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1];
	matrix_res[1][0] = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0];
	matrix_res[1][1] = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1];
	printf("Task 2:\n");
	printf("[[%d, %d]\n", matrix_res[0][0], matrix_res[0][1]);
	printf(" [%d, %d]]\n", matrix_res[1][0], matrix_res[1][1]);

	return 0;
}