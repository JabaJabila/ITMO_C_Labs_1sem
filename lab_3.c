#include <stdio.h>

int main() {
	// Объявление переменнных
	int num1 = 0, num2 = 0;
	printf("Task 1 - input octal number: ");
	scanf("%o", &num1); // Ввод с консоли первого числа (8 сс/ч)

	printf("Task 2: %d\n", num1); // Печать в 10 сс/ч

	printf("Task 3: %o -> %o\n", num1, num1 << 1); // Сдвиг на 1 бит влево
	// Печать числа в 8 cc/ч до и после битового отрицания
	printf("Task 4: %o -> %o\nTask 5 - input one more octal num: ", num1, ~num1);
	scanf("%o", & num2); // Ввод с консоли еще одного числа (8 cc/ч)
	printf("Task 5: %o\n", num1 & num2); // Вывод результата битовой оперции И над двумя числами

	return 0;
}