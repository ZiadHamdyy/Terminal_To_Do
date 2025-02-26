#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <wchar.h>
#include <stddef.h>
#include <locale.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

struct Task {
    int id;
    char name[100];
    int status;
};

char* formatTask(struct Task task);
void printTasks(struct Task* tasks, int taskCount);
struct Task* getTasks(int *taskCount);
void addTask(char *name);
void deleteTask(int line);
void checkTask(int taskNumber);
#endif