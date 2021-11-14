#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab_15_arc.h"

// КОДЫ ОШИБОК:
// 10 - файл не найден
// 11 - аргументы командной строки заданы неверно

int main(int argc, char ** argv) {

	FILE * archive = NULL;
	char flag = 0; // флаг: 0 - неизвестный аргумент / 1 - допуск на чтение n файлов / 2 - запрет на чтение n файлов

	// Обработка аргументов командной строки (все случаи)
	if (argc >= 3 && strcmp("--file", argv[1]) == 0) {

		if (argc == 3) {
			fprintf(stderr, "Error! \"%s\" requires more arguments", argv[0]);
    		exit(11);
		}
	}

	else {

		fprintf(stderr, "Error! Use \"--file [filename]\"");
    	exit(11);
	}

	if (argc >= 4 && strcmp("--create", argv[3]) == 0) {

		if (argc == 4) {
			fprintf(stderr, "Error! \"--create requires more arguments");
    		exit(11);
		} 

		archive = fopen(argv[2], "wb");
		flag = 1;
	}

	else if (argc >= 4 && strcmp("--extract", argv[3]) == 0) { 

		if (argc > 4) {
			fprintf(stderr, "Error! \"--extract doesn't requires any arguments");
    		exit(11);
		}

		archive = fopen(argv[2], "rb");
		if (archive == NULL) {
			fprintf(stderr, "Error! File not found");
            fclose(archive);
    		exit(10);
		}

		extract(archive); // распаковка архива
		flag = 2;
	}

	else if (argc >= 4 && strcmp("--list", argv[3]) == 0) { 

		if (argc > 4) {
			fprintf(stderr, "Error! \"--list doesn't requires any arguments");
    		exit(11);
		}

		archive = fopen(argv[2], "rb");
		if (archive == NULL) {
			fprintf(stderr, "Error! File not found");
            fclose(archive);
    		exit(10);
		}

		list(archive, argv); // перечисление содержимого
		flag = 2;
	}

	if (flag == 1) { 

		create(archive, argc, argv); // создание архива
	}

	else if (flag == 0) {
		fprintf(stderr, "Error! Unknown arguments");
    	exit(11);
	}

	return 0;
}
