#include "task.h"
#include <stdio.h>
#include <stdlib.h>

void checkTask(int taskNumber) {
    FILE *file = fopen("tasks.txt", "r+");
    if (file == NULL) {
        printf("Failed to open file");
        return;
    }

    int ch;
    int currentTask = 1;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            currentTask++;
        }
        if (currentTask == taskNumber && (ch == '0' || ch == '1')) {
            fseek(file, -1, SEEK_CUR);
            if (ch == '0') {
                fputc('1', file);
            } else {
                fputc('0', file);
            }
            break;
        }
    }

    fclose(file);
}