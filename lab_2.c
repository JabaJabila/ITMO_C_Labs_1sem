#inc lude <stdio.h>
#include <math.h>

int main() {
	// Объявление переменных (числа с плавающей точкой)
	double alpha = 0, z1 = 0, z2 = 0;
	printf("Input alpha (degrees): ");
	// Ввод переменной alpha (в градусах)
	scanf("%lf", &alpha);
	// Перевод градусов в радианы
	alpha = alpha * M_PI / 180;

	// Расчёт значений функций
	z1 = 2 * pow(sin(3 * M_PI - 2 * alpha), 2.0) * pow(cos(5 * M_PI + 2 * alpha), 2.0);
	z2 = 0.25 - 0.25 * sin(2.5 * M_PI - 8 * alpha);
	// Вывод значений
	printf("Output:\nz1 = %lf\nz2 = %lf\n", z1, z2);

	return 0;
}