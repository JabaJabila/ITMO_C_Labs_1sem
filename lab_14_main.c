#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "lab_14_bmp.h"
#include "lab_14_gol.h"

// TODO:
// - наладить работу с МОНОХРОМНЫМИ bmp

// ERRORS:

// 10 - file not found
// 11 - wrong arguments

int main(int argc, char * argv[]) {

	int maxiter = 10000000, dumpfreq = 1;
	char * dirname = NULL;
	FILE * file = NULL;

	// Обработка аргументов командной строки
	if (argc >= 3 && strcmp("--input", argv[1]) == 0) {

		file = fopen(argv[2], "rb");

		if (file == NULL) {

            fprintf(stderr, "Error! File not found");
            fclose(file);
    		exit(10);
        }
	}
	else {

		fprintf(stderr, "Error! Use \"--input [filename]\" to open BMP file");
    	exit(11);
	}

	if (argc >= 5 && strcmp("--output", argv[3]) == 0) {

		dirname = argv[4];
		mkdir(dirname);
	}
	else {

		fprintf(stderr, "Error! Use \"--output [dirname]\" to choose where to save generated BMP files");
    	exit(11);
	}

	if (argc >= 7 && strcmp("--max_iter", argv[5]) == 0)
		maxiter = strtol(argv[6], 0, 10);

	if (argc >= 7 && strcmp("--dump_freq", argv[5]) == 0) 
		dumpfreq = strtol(argv[6], 0, 10);

	else if (argc >= 9 && strcmp("--dump_freq", argv[7]) == 0)
		dumpfreq = strtol(argv[8], 0, 10);

	// Обработка BMP файла
	struct BMP Image = parseBMP(file);

	char ** img = (char **)malloc(Image.height * sizeof(char *));

	for (int i = 0; i < Image.height; i++)
		img[i] = (char *)malloc(Image.width * sizeof(char));

	int k = 0;

	// Копия данных о положении точек
	for (int i = Image.height - 1; i >= 0; i--) 
		for (int j = 0; j < Image.width; j++) {

			if (Image.content[k] == 255)
				img[i][j] = 0;

			else
				img[i][j] = 1;

			k += 3;
		}

	// Логика игры
	for (int l = 1; l <= maxiter; l++) {

		generation(img, Image.height, Image.width); // Симуляция одного поколения

		if (l % dumpfreq != 0)
			continue;

		makeBitMap(Image, img, dirname, l); // Создание BMP файла
	}

	// Освобождение выделенной динамической памяти
	for (int i = 0; i < Image.height; i++) 
		free(img[i]);

	free(img);
	free(Image.content);

	return 0;
}
