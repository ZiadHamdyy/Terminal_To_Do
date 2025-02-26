#include "task.h"

void deleteTask(int line) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("File not found\n");
        return;
    }
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Error creating temporary file");
        fclose(file);
        return;
    }

    char buffer[1024];
    int current_line = 1;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (current_line != line) {
            fputs(buffer, temp_file);
        }
        current_line++;
    }

    fclose(file);
    fclose(temp_file);

    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
}