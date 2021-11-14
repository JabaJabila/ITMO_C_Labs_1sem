#include <malloc.h>

void generation(char ** array, unsigned height, unsigned width) {

	unsigned neighbours;
	char ** tmp = (char **)malloc(sizeof(char *) * height);

	for (int i = 0; i < height; i++)
		tmp[i] = (char *)malloc(sizeof(char) * width);

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			tmp[y][x] = array[y][x];

	for (int y = 1; y < height - 1; y++) {

		for (int x = 1; x < width - 1; x++) {

			neighbours = array[y + 1][x - 1] + array[y + 1][x] + array[y + 1][x + 1] + array[y][x - 1] \
						 + array[y][x + 1] + array[y - 1][x - 1] + array[y - 1][x] + array[y - 1][x + 1];
			
			if (tmp[y][x] == 1) {

				if (neighbours == 2)
					tmp[y][x] = array[y][x];

				if (neighbours == 3)
					tmp[y][x] = array[y][x];

				if (neighbours > 3)
					tmp[y][x] = 0;

				if (neighbours < 2)
					tmp[y][x] = 0;
			}

			else
				if (neighbours == 3)
					tmp[y][x] = 1;

			neighbours = 0;
		}
	}

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++) {
			array[y][x] = tmp[y][x];
		}

	for (int i = 0; i < height; ++i)
		free(tmp[i]);

	free(tmp);
}