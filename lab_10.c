#include <stdio.h>
#include <malloc.h>
#include <math.h>

// функция нахождения НОД двух чисел
int grComDiv(int a, int b) {
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

// функция нахождения НОК двух чисел
int lComMult(int a, int b) {
	return a * b / grComDiv(a, b);
}

// структура точки с координатами x и y
struct Point {
	double x;
	double y;
};

// функция по нахождению расстояния между двумя точками
double distance(struct Point p1, struct Point p2) {
	return sqrt(pow(p2.x - p1.x, 2.0) + pow(p2.y - p1.y, 2.0));
}

// функция, создающая массив размером n на n - 1, содержащий расстояния между точками
double ** generatedist(int n, struct Point * array) {
	double ** dist = (double **)malloc(n * sizeof(double *));
	int counter;
	for (int i = 0; i < n; i++) {
		counter = 0;
		dist[i] = (double *)malloc((n - 1) * sizeof(double));
		for (int j = 0; j < n; j++) {
			if (j != i) {
				dist[i][counter] = distance(array[i], array[j]);
				counter++;
			}
		}
	}
	return dist;
}

int main() {
	int num1, num2, n;
	scanf("%d %d", &num1, &num2);
	printf("\nNOD = %d\nNOK = %d\n\n", grComDiv(num1, num2), lComMult(num1, num2));
	scanf("%d", &n);

	struct Point * array = (struct Point *)malloc(n * sizeof(struct Point));
	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &array[i].x, &array[i].y);

	double ** distancearray = generatedist(n, array);
	printf("\nArray of distances:\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++)
			printf("%.3lf ", distancearray[i][j]);
		printf("\n");
	}

	free(array);
	array = NULL;
	for (int i = 0; i < n; i++) {
		free(distancearray[i]);
		distancearray[i] = NULL;
	}
	free(*distancearray);
	distancearray = NULL;

	return 0;
}