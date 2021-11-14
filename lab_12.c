#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // обработка аргументов командной строки
    if (argc <= 1)
        printf("Error! use %s --name [filename] to create file\n", argv[0]);

    else if (strcmp(argv[1], "--name") != 0)
         printf("Error! unknown parameter\n");

    else if (strcmp(argv[1], "--name") == 0 & argc <=2)
        printf("Error! no filename\n");

    else {
    	time_t rawtime;
        time_t * p_time = &rawtime;
        struct tm * timeinfo;
        char buffer[20];
        time(p_time); // получить текущее время (кол-во секунд)

        FILE *fout;
        fout = fopen(argv[2], "w"); // создание и открытие файла для записи
        fprintf(fout, "Ближайшие 10 дней:\n");

        // цикл преобразования времени строку даты
        for (int i = 1; i <= 10; i++) {
        	timeinfo = localtime(p_time);
        	strftime(buffer, 20, "%d/%m/%Y", timeinfo);
        	fprintf(fout, "%s\n", buffer);
        	rawtime += 60 * 60 * 24; // прибавление количества секунд в одном дне
        }

        fclose(fout); //
    }
	
	return 0;
}