#include "task.h"

/* struct Task* getTasks(int *taskCount) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("File not found\n");
        return NULL;
    }

    // Count the number of tasks in the file
    int count = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (buffer[0] != '\n') { // Ignore empty lines
            count++;
        }
    }

    // Allocate memory for the tasks
    struct Task *tasks = malloc(count * sizeof(struct Task));
    if (tasks == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    // Reset the file pointer to the beginning
    rewind(file);

    // Read tasks from the file
    int index = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (buffer[0] != '\n') { // Ignore empty lines
            tasks[index].id = index + 1;

            // Remove the newline character (if present)
            buffer[strcspn(buffer, "\n")] = '\0';

            // Copy the task name
            strcpy(tasks[index].name, buffer);

            tasks[index].status = 0; // Default status
            index++;
        }
    }

    fclose(file);
    *taskCount = count; // Return the number of tasks
    return tasks; // Return the dynamically allocated array of tasks
} */

struct Task* getTasks(int *taskCount) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("File not found\n");
        return NULL;
    }

    int count = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
            count++;
    }
    printf("Count: %d\n", count);

    struct Task *tasks = malloc(count * sizeof(struct Task));
    if (tasks == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    rewind(file);

    int index = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (buffer[0] != '\n' && buffer[0] != '\0') { // Ignore empty lines
            tasks[index].id = index + 1;

            // Extract the name and status from the buffer
            char *nameStart = strchr(buffer, '"'); // Find the first double quote
            char *nameEnd = strchr(nameStart + 1, '"'); // Find the second double quote
            char *statusStart = strchr(nameEnd + 1, ','); // Find the comma after the name
            int status;

            if (nameStart && nameEnd && statusStart) {
                // Extract the name
                strncpy(tasks[index].name, nameStart + 1, nameEnd - nameStart - 1);
                tasks[index].name[nameEnd - nameStart - 1] = '\0'; // Null-terminate the name

                // Extract the status
                sscanf(statusStart + 1, "%d", &status);
                tasks[index].status = status;
            } else {
                // Handle invalid format
                strcpy(tasks[index].name, "Invalid Task");
                tasks[index].status = -1;
            }

            index++;
        }
    }

    fclose(file);
    *taskCount = count;
    return tasks;
}

/* int main(){
    int taskCount;
    struct Task *tasks = getTasks(&taskCount);
    printf("Task Count: %s\n", tasks[0].name);
    printf("Task Count: %d\n", tasks[0].status);
    printf("Task Count: %s\n", tasks[2].name);
    printf("Task Count: %d\n", tasks[2].status);
    return 0;
} */