#include <stdio.h>

int main() {
	// Объявление переменных и их ввод первого числа через консоль
	int num1 = 0, num2 = 0;
	printf("Task 1 - input first number: ");
	scanf("%d", &num1);
	// Вывод проверки на нахождение числа в диапазоне 1-10
	// 1 - число в диапазоне | 0 - нет
	printf("%d\n", (num1 >= 1) && (num1 <= 10));

	printf("Task 2 - input second number: ");
	scanf("%d", &num2); // Ввод второго числа через консоль
	printf("%d\n", (num2 >> 1) & 1); // Печать первого бита второго числа
	printf("%d\n", (num2 / 2) % 2);

	return 0;
}