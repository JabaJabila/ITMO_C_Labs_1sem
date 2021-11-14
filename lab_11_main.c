#include <stdio.h>
#include "lab_11_rectangle.h"

int main() {
    unsigned double w, h;
    double x, y;

    scanf("%lf %lf %lf %lf", &w, &h, &x, &y);

	struct Rectangle rect = CreateRect(w, h, x, y);

    printf("Area of rectangle with sides %d x %d = %d\n", \
        rect.width, rect.height, GetRectArea(rect));
    
    printf("Perimeter of rectangle with sides %d x %d = %d\n", \
        rect.width, rect.height, GetRectPerimeter(rect));

	return 0;
}