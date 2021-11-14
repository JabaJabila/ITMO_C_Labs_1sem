#include <stdio.h>

int lenstr(char *str) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i - 1;
}

void concat(char *str1, char *str2) {
	int len1 = lenstr(str1);
	int len2 = lenstr(str2);
	for(int i = 0; i < len2; i++)
		str1[len1 + i + 1] = str2[i];
	str1[len1 + len2 + 1] = '\0';
}

void copy(char *str1, char *str2) {
	int len1 = lenstr(str1);
	int len2 = lenstr(str2);
	for (int i = 0; i < len2; i++)
		str2[i] = 32;
	for (int i = 0; i < len1; i++)
		str2[i] = str1[i];
	str2[len1] = '\0';
}
// -1 - str1 > str2 | 1 - str1 < str2 | 0 - str1 = str2
int comparsion(char *str1, char *str2) {
	int len1 = lenstr(str1);
	int len2 = lenstr(str2);
	if (len2 > len1) {
		int tmp = len1;
		len1 = len2;
		len2 = tmp;
	}
	for (int i = 0; i < len1; i++) {
		if (str1[i] > str2[i])
			return -1;
		if (str1[i] < str2[i])
			return 1;
	}
	if (len1 = len2)
		return 0;
	if (lenstr(str1) > lenstr(str2))
		return -1;
	return 1;
}

int lsearch(char *str, char symbol) {
	int len = lenstr(str);
	for (int i = len; i >= 0; i--)
		if (str[i] == symbol)
			return i;
	return -1;
}

int main() {
	char str1[100], str2[100], strconcat[200], symbol;
	// Ввод первой строки через стандартный поток ввода
	fgets(str1, 100, stdin);
	// Очистака потока ввода
	fflush(stdin);
	// Ввод второй строки через стандартный поток ввода
	fgets(str2, 100, stdin);
	// Очистака потока ввода
	fflush(stdin);

	// Конкатенация двух строк
	copy(str1, strconcat);
	concat(strconcat, str2);

	printf("Concatenation of two strings: %s", strconcat);

	// Сравнение двух строк
	printf("\nComparsion of two strings: %d\n", comparsion(str1, str2));

	// Копирование первой строки
	copy(str1, str2);
	printf("\nCopied string #1: %s", str2);

	// Нахождение длины первой строки
	printf("\nLength of string #1: %d\n", lenstr(str1));

	// Ввод символа
	scanf("%c", &symbol);
	// Печать индекса последнего вхождения символа в первую строку
	printf("Index of the last occurence of symbol in string #1: %i\n",\
		lsearch(str1, symbol));

    return 0;
}