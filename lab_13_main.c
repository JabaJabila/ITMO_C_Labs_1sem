#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char argument[100];
    // обработка аргументов командной строки

    if (argc == 1 || strncmp(argv[1], "--filepath=", 11) != 0 ) {
        printf("Error! use %s --filepath=[filename] to read from file...\n", argv[0]);
    }

    else {

        if (argc <= 2) {
            printf("Error! no commands found\n");
        }

        // read
        // error if unable to read

        if (strcmp(argv[2], "--show" ) == 0 && argc == 3) {
            printf("Show\n");
            // show()
        }

        else if (strncmp(argv[2], "--get=", 6) == 0 && argc == 3) {
            printf("Get\n");
            // get()
        }


        else if (strncmp(argv[2], "--set=", 6) == 0) {
            if (argc != 4 || strncmp(argv[3], "--value=", 8) != 0)
                printf("Error! no value\n");
            else
                // set(target, value)
        }

        else {
            printf("Error! unknown arguments\n");
        }

    }
    
    return 0;
}