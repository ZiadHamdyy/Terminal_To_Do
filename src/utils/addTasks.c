#include "task.h"

void addTask(char *name) {
    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        printf("File not found\n");
        return;
    }

    fprintf(file, "{\"%s\", 0}\n", name);

    fclose(file);
}