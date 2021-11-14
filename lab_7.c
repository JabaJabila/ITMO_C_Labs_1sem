#include <stdio.h>

enum WeekDay {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Rectangle {
    unsigned width; // ширина прямоугольника
    unsigned height; // высота прямоугольника
    int leftCornerX; // x координата левого нижнего угла
    int leftCornerY; // y координата левого нижнего угла
};

// функция вычисления площади прямоугольника
unsigned GetRectArea(struct Rectangle rectangle) {
    return rectangle.width * rectangle.height;
}

// создание битового поля состояния элементов mp3 проигрывателя
struct Elements {
    unsigned Recording: 1;
    unsigned Pause: 1;
    unsigned Play: 1;
};

union Checker {
    unsigned number;
    struct Elements Status;
};

union Checker CheckElements;

int main() {

    printf("Task 1: Monday = %d\n", Monday);

    // создание прямоугольника и печать его площади
    struct Rectangle rect;
    rect.width = 3;
    rect.height = 4;
    rect.leftCornerX = 6;
    rect.leftCornerY = -2;
    printf("Task 2: Area of rectangle with sides %d x %d = %d\n", \
        rect.width, rect.height, GetRectArea(rect));

    // Ввод 16-ого числа 
    printf("Input a hex number: ");
    scanf("%x", &CheckElements.number);
    // Вывод состояний элементов mp3 проигрывателя
    printf("Task 3:\nPlay = %d\n", CheckElements.Status.Play);
    printf("Pause = %d\n", CheckElements.Status.Pause);
    printf("Recording = %d\n", CheckElements.Status.Recording);

    return 0;
}
