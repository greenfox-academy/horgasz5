#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "todo.h"

void startup()
{
    printf("Todo application\n");
    printf("====================\n");
    printf("Commands:\n");
    printf("-a   Adds a new task\n");
    printf("-wr  Write current todos to file\n");
    printf("-rd  Read todos from a file\n");
    printf("-l   Lists all the tasks\n");
    printf("-e   Empty the list\n");
    printf("-r   Removes a task\n");
    printf("====================\n");
    printf("Your command: \n");
}

void lista_init(lista *storage)
{
    storage->arr = NULL;
    storage->length = 0;
}

void lista_deinit(lista *storage)
{
    free(storage->arr);
    storage->arr = NULL;
    storage->length = 0;
}

void clrscr()
{
    system("@cls||clear");
}

 int add_task(lista *storage, char *todo)
{
    int new_length = storage->length + 1;
    storage->arr = realloc(storage->arr, sizeof(doing) * new_length);
    storage->length = new_length;
    strcpy(storage->arr[new_length - 1].todo, todo);
    clrscr();
    startup();
    return 0;
}

int listing(lista *storage)
{
    if (storage == NULL)
        return -1;
    clrscr();
    printf("List by number\n");
    printf("====================\n");
    printf("Num | Tasks\n");
    for (int i = 0; i < storage->length; i++) {
        printf("%d  ", i + 1);
        printf(" - %s", storage->arr[i].todo);
        printf("\n");
    }
    return 0;
}

int write(lista *storage, char *path)
{
    if (storage == NULL || path == NULL)
        return -1;

    FILE *file = fopen(path, "w");
    if (file == NULL)
        return -1;

    for (int i = 0; i < storage->length; i++) {
        fprintf(file, "%s\n", storage->arr[i].todo);
    }

    fclose(file);
    return 0;
}

int read(lista *storage, char *path)
{
    if (storage == NULL || path == NULL)
        return -1;

    FILE *file = fopen(path, "r");
    if (file == NULL)
        return -1;

    char todo[MAX_LEN];

    while(fscanf(file, "%s\n", todo) == 1) {
        add_task(storage, todo);
    }

    fclose(file);
    return 0;
}

int empt(lista *storage)
{
    if (storage == NULL)
        return -1;
    lista_deinit(storage);
    printf("No todos for today! :)\n");
    return 0;
}
