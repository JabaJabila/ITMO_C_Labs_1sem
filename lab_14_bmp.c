#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BMP {

	unsigned char header[54];
	unsigned width;
	unsigned height;
	unsigned size;
	unsigned char * content;
};

struct BMP parseBMP(FILE * file) {

	struct BMP Image;

	fread(Image.header, sizeof(unsigned char), 54, file);

	Image.width = Image.header[21] * 256 * 256 * 256 + Image.header[20] * 256 * 256 + Image.header[19] * 256 + Image.header[18];
	Image.height = Image.header[25] * 256 * 256 * 256 + Image.header[24] * 256 * 256 + Image.header[23] * 256 + Image.header[22];
	Image.size = Image.header[5] * 256 * 256 * 256 + Image.header[4] * 256 * 256 + Image.header[3] * 256 + Image.header[2];

	Image.content = (unsigned char *)malloc((Image.size - 54) * sizeof(unsigned char));
	fread(Image.content, sizeof(unsigned char), Image.size, file);

	return Image;
}

void makeBitMap(struct BMP Image, char ** array, char * dirname, int counter) {

	char path[256];
	char filename[16];

	strcpy(path, dirname);
	strcat(path, "\\");
	strcat(path, itoa(counter, filename, 10));
	strcat(path, ".bmp");

	FILE * gen = fopen(path, "wb");
	fwrite(Image.header, 1, 54, gen);
	int m = 0;

	for (int i = Image.height - 1; i >= 0; i--) 
		for (int j = 0; j < Image.width; j++) 

			for (int k = 0; k < 3; k++) {

				if (array[i][j] == 1)
					Image.content[m] = 0;

				else
					Image.content[m] = 255;

				m++;
			}

	fwrite(Image.content, sizeof(unsigned char), Image.size, gen);
	fclose(gen);
}

