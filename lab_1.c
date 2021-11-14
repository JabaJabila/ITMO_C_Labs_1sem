#include <stdio.h>

int main() {
	// Объявление строки длинной 100 символов и целого числа
	char str[100];
	int x = 0;

	printf("INPUT:\n");
	// Ввод строки через стандартный поток ввода
	fgets(str, 100, stdin);
	// Очистака потока ввода
	fflush(stdin);
	// Ввод целого числа
	scanf("%d", &x);

	printf("\nOUTPUT:\n");
	// Вывод строки
	fputs(str, stdout);
	// Вывод числа
	printf("%d\n", x);

	return 0;
}