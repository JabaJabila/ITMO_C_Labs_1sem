struct Rectangle {
    unsigned double width; // ширина прямоугольника
    unsigned double height; // высота прямоугольника
    double leftCornerX; // x координата левого нижнего угла
    double leftCornerY; // y координата левого нижнего угла
};

// функция, создающая прямоугольник по введённым параметрам
struct Rectangle CreateRect(unsigned double width, unsigned double height, double leftCornerX, double leftCornerY) {
	struct Rectangle rect;
	rect.width = width;
	rect.height = height;
	rect.leftCornerX = leftCornerX;
	rect.leftCornerY = leftCornerY;
	return rect;
}

// функция вычисления площади прямоугольника
unsigned double GetRectArea(struct Rectangle rectangle) {
    return rectangle.width * rectangle.height;
}

// функция вычисления периметра прямоугольника
unsigned double GetRectPerimeter(struct Rectangle rectangle) {
    return rectangle.width * 2 + rectangle.height * 2;
}