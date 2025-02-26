#include <stdio.h>
#include "task.h"

int operations(){
    int choice;
    printf("1. Print Tasks\n");
    printf("2. Add Task\n");
    printf("3. Delete Task\n");
    printf("4. Check Task\n");
    printf("0. Exit\n");
    printf("Enter your choice from (0 -> 4): ");
    scanf("%d", &choice);
    if (isalpha(choice)) {
        printf("Invalid choice\n");
        return 100;
    }
    return choice;
}


int main(){
    /* struct Task tasks[6] = {
        {1, "Task 1 Task 1 Task 1", 0},
        {2, "Task 2", 1},
        {3, "Task 3", 0},
        {4, "Task 4 Task 4", 0},
        {5, "Task 5", 0},
        {6, "Task 6 Task 6 Task 6", 0}
    }; */
    while (1) {
        int choice = operations();
        /* if (choice == 0) {
            int taskCount;
            struct Task *tasks = getTasks(&taskCount);
            if (tasks != NULL) {
                printTasks(tasks, taskCount);
                free(tasks);
            } else {
                printf("Failed to read tasks.\n");
            }
        } else if (choice == 1) {
            char taskName[100];
            printf("Enter the task name: ");
            scanf(" %[^\n]", taskName);
            addTask(taskName);
        } else if (choice == 2) {
            // deleteTask(tasks, 6);
        } else if (choice == 3) {
            // checkTask(tasks, 6);
        } else if (choice == 4) {
            break;
        } else if (choice != 4 || choice != 3 || choice != 2 || choice != 1 || choice != 0) {
            break;
        } */

        switch (choice) {
            case 0:
                printf("Exit\n");
                return 0;
            case 1:
                int taskCount;
                struct Task *tasks = getTasks(&taskCount);
                if (tasks != NULL) {
                    printTasks(tasks, taskCount);
                    free(tasks);
                } else {
                    printf("Failed to read tasks.\n");
                }
                break;
            case 2:
                char taskName[100];
                printf("Enter the task name: ");
                scanf(" %[^\n]", taskName);
                addTask(taskName);
                break;
            case 3:
                int line;
                printf("Enter the line number to delete: ");
                scanf("%d", &line);
                deleteTask(line);
                break;
            case 4:
                printf("Enter the line number to Check: ");
                scanf("%d", &line);
                checkTask(line);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    // int size = sizeof(tasks) / sizeof(tasks[0]);
    // printTasks(tasks, size);
    
    return 0;
}