#include <stdio.h>
#define FREE_MINS 499

int main() {
	int symbols = 0, digits = 0, b_symb = 0, s_symb = 0;
	char str[100] = {0};

	printf("String: "); // ввод строки
	fgets(str, 100, stdin);
	fflush(stdin);

	// подсчёт кол-ва букв и цифр
	for (int i = 0; i < 100; i++) {
		if ((str[i] >= 48) && (str[i] <= 57)) 
			digits++;
		else if ((str[i] >= 65) && (str[i] <= 90)) {
			symbols++;
			b_symb++;
		}

		else if	((str[i] >= 97) && (str[i] <= 122)) {
			symbols++;
			s_symb++;
		}
	}

	printf("Digits: %d\nLetters: %d\nBig letters: %d\nSmall letters: %d\n", digits, symbols, b_symb, s_symb);
	
	float mins, tariff, over_limit;

	// ввод с клавиатуры данных для второй задачи
	printf("Minutes, price for tariff and price for minute over limit:\n");
	scanf("%f %f %f", &mins, &tariff, &over_limit);
	
	// сообщение об ошибке
	if (tariff / FREE_MINS >= over_limit)
		printf("Minutes are more profitable than tariff!!!\n");
	
	// расчёт стоимости тарифа 
	else {
		if (mins <= FREE_MINS)
			printf("Fee = %.2f\n", tariff);
		else
			printf("Fee = %.2f\n", tariff + (mins - FREE_MINS) * over_limit);
	}

	return 0;
}