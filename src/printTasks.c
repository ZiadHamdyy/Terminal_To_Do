#include "task.h"

char* formatTask(struct Task task) {
    setlocale(LC_ALL, "");

    static char buffer[1000];
    buffer[0] = '\0';

    strcat(buffer, " ___________\n");

    char idLine[50];
    sprintf(idLine, "(     %d     )\n", task.id);
    strcat(buffer, idLine);

    int len = strlen(task.name);
    int maxWidth = 9;
    int start = 0;

    while (start < len) {
        int end = start + maxWidth;
        if (end > len) {
            end = len;
        }

        char nameLine[20];
        sprintf(nameLine, "| ");
        for (int i = start; i < end; i++) {
            char ch = task.name[i];
            char temp[2] = {ch, '\0'};
            strcat(nameLine, temp);
        }
        for (int i = end - start; i < maxWidth; i++) {
            strcat(nameLine, " ");
        }
        strcat(nameLine, " |\n");
        strcat(buffer, nameLine);

        start = end;
    }

    char statusLine[50];
    sprintf(statusLine, "(____ %s ____)\n", task.status == 0 ? "✖" : "✔");
    strcat(buffer, statusLine);

    return buffer;
}
void printTasks(struct Task* tasks, int size) {
    for (int i = 0; i < size; i++) {
            printf("%s",formatTask(tasks[i]));
    }
}