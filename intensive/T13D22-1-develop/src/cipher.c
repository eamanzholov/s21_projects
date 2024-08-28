#include <stdio.h>
#include <stdlib.h>

#include "logger.c"

#define LENGTH 256

int readFile(char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("n/a");
        return 1;
    }
    int size = 0;
    int ch;
    char *data = NULL;

    while ((ch = fgetc(file)) != EOF) {
        data = realloc(data, (size + 1) * sizeof(char));
        if (data == NULL) {
            printf("n/a");
            fclose(file);
            return 1;
        }
        data[size] = (char)ch;
        size++;
    }
    data = realloc(data, (size + 1) * sizeof(char));
    data[size] = '\0';
    if (size == 0) {
        printf("n/a");
        return 1;
    }
    printf("%s", data);
    free(data);
    fclose(file);
    return 0;
}
int writeFile(char *filePath) {
    char fff[LENGTH];
    scanf("%255s", fff);

    FILE *file1 = fopen(filePath, "r");
    if (file1 == NULL) {
        return 1;
    }
    FILE *file = fopen(filePath, "a");
    if (file == NULL) {
        return 1;
    }
    fprintf(file, "%s", fff);

    fclose(file);
    return 0;
}

int main() {
    char log_path[10] = "log.txt";
    FILE *log_file = log_init(log_path);
    if (log_file == NULL) {
        printf("n/a");
        return -1;
    }

    int choice = 0;
    char filePath[LENGTH];

    do {
        if (scanf("%d", &choice) != 1) {
            printf("n/a\n");
            exit(1);
        }
        switch (choice) {
            case 1:
                if (scanf("%255s", filePath) != 1) {
                    printf("n/a\n");
                    exit(1);
                }
                readFile(filePath);
                break;
            case 2:
                writeFile(filePath);
                readFile(filePath);
                break;
            case 3:
                if (scanf("%255s", filePath) != 1) {
                    printf("n/a\n");
                    exit(1);
                }
                readFile(filePath);
                break;
            case 4:
                if (scanf("%255s", filePath) != 1) {
                    printf("n/a\n");
                    exit(1);
                }
                readFile(filePath);
                break;
            case -1:
                exit(0);
                break;
            default:
                printf("n/a\n");
                break;
        }
        printf("\n");
    } while (choice != -1);
    return 0;
}
