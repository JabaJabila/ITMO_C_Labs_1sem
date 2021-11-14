#ifndef LAB_11_RECTANGLE_H
#define LAB_11_RECTANGLE_H

struct Rectangle {
    unsigned double width; // ширина прямоугольника
    unsigned double height; // высота прямоугольника
    double leftCornerX; // x координата левого нижнего угла
    double leftCornerY; // y координата левого нижнего угла
};

// сигнатуры функций из lab_11_rectangle.c
struct Rectangle CreateRect(unsigned double, unsigned double, double, double);

unsigned GetRectArea(struct Rectangle);

unsigned GetRectPerimeter(struct Rectangle);

#endif