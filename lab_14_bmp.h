#ifndef LAB_14_BMP_H
#define LAB_14_BMP_H

struct BMP {

	unsigned char header[54];
	unsigned width;
	unsigned height;
	unsigned size;
	unsigned char * content;
};

struct BMP parseBMP(FILE *);

void makeBitMap(struct BMP, char **, char *, int);

#endif