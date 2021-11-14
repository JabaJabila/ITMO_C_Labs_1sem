#include <stdio.h>
#include <malloc.h>
#define LEN_ARRAY 4

int main() {
	char array[LEN_ARRAY];
	char * pointer = array;
	array[0] = 'a';
	array[1] = 'b';
	array[2] = 'c';
	array[3] = 'd';

	printf("Task 1: [");
	for (int i = 0; i <= LEN_ARRAY - 2; i++) {
		printf("%c, ", *(pointer + i));
	}
	printf("%c]\n", *(pointer + LEN_ARRAY - 1));

	char * d_array = (char *)malloc(LEN_ARRAY * sizeof(char));

	d_array[0] = 'a';
	d_array[1] = 'b';
	d_array[2] = 'c';
	d_array[3] = 'd';

	printf("Task 2: [");
	for (int i = 0; i <= LEN_ARRAY - 2; i++) {
		printf("%c, ", d_array[i]);
	}
	printf("%c]\n", d_array[LEN_ARRAY - 1]);

	free(d_array);
	d_array = NULL;
	return 0;
}