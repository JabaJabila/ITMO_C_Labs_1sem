#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// получение размера файла из прочитанных 4 байтов
unsigned get_size(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4) {

	return (unsigned)(c1 * 256 * 256 * 256 + c2 * 256 * 256 + c3 * 256 + c4);
}

// создание архива
void create(FILE * archive, int argc, char ** argv) {

	unsigned char c1 = (argc - 4) / 256 / 256 / 256, c2 = (argc - 4) / 256 / 256 % 256,
    	c3 = (argc - 4) / 256 % 256, c4 = (argc - 4) % 256;

	fprintf(archive, "%c%c%c%c", c1, c2, c3, c4); // запись кол-ва запакованных файлов

	for (int i = 0; i < argc - 4; i++) {

		FILE * file = fopen(argv[4 + i], "rb");

		if (file == NULL) {
			fprintf(stderr, "Error! File not found");
            fclose(archive);
    		exit(10);
		}

		fseek(file, 0, SEEK_END);
    	unsigned filesize = ftell(file); // определение размера файла
    	fseek(file, 0, SEEK_SET);

    	c1 = filesize / 256 / 256 / 256; c2 = filesize / 256 / 256 % 256;
    	c3 = filesize / 256 % 256; c4 = filesize % 256;

		fprintf(archive, "%s\n%c%c%c%c", argv[4 + i], c1, c2, c3, c4); // запись размера запакованного файла

		char c;
		for (unsigned i = 0; i < filesize; i++) { // запись содержимого файла
    		c = getc(file);
        	putc(c, archive);
    	}
	}

	fclose(archive);
}

// распаковка архива
void extract(FILE * archive) {

	unsigned char c1, c2, c3, c4;
	fscanf(archive, "%c%c%c%c", &c1, &c2, &c3, &c4); // чтение кол-ва запакованных файлов
	unsigned n = get_size(c1, c2, c3, c4);

	for (int i = 0; i < n; i++) {

		char filename[100];
		fscanf(archive, "%s\n%c%c%c%c", filename, &c1, &c2, &c3, &c4); // чтение размера запакованного файла
		unsigned filesize = get_size(c1, c2, c3, c4);

		FILE * file = fopen(filename, "wb"); // создание отдельного файла

		char c;
		for (unsigned i = 0; i < filesize; i++) { // запись содержимого в новый файл
    		c = getc(archive);
        	putc(c, file);
    	}

    	fclose(file);
	}

	fclose(archive);
}

// перечисление содержимого
void list(FILE * archive, char ** argv) {

	unsigned char c1, c2, c3, c4;
	fscanf(archive, "%c%c%c%c", &c1, &c2, &c3, &c4); // чтение кол-ва запакованных файлов
	unsigned n = get_size(c1, c2, c3, c4);

	printf("\"%s\" contains %d file(s):\n\n", argv[2], n); // печать: "[название архива] содержит [кол-во] файл(ов):"

	for (int i = 0; i < n; i++) {

		char filename[100];
		fscanf(archive, "%s\n%c%c%c%c", filename, &c1, &c2, &c3, &c4); // чтение размера запакованного файла
		unsigned filesize = get_size(c1, c2, c3, c4);

		fseek(archive, filesize, SEEK_CUR); // пропуск содержимого запакованного файла
		printf("%-35s%12d bytes\n", filename, filesize); // печать: "[название файла]      [размер] байт"
	}

	fclose(archive);
}