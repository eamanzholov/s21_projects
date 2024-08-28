#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DoorState {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

int compare_record(const void *a, const void *b) { return memcmp(a, b, sizeof(struct DoorState)); }

void print_record(const struct DoorState *record) {
    printf("%d %d %d %d %d %d %d %d\n", record->year, record->month, record->day, record->hour,
           record->minute, record->second, record->status, record->code);
}

int main() {
    char filename[256];

    printf("Enter the filename: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "rb+");
    if (!file) {
        printf("n/a");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int records_count = ftell(file) / sizeof(struct DoorState);
    fseek(file, 0, SEEK_SET);

    int choice;
    do {
        printf("Menu:\n");
        printf("0 - Print file content\n");
        printf("1 - Sort and print file content\n");
        printf("2 - Add record, sort, and print file content\n");
        printf("3 - Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                for (int i = 0; i < records_count; ++i) {
                    struct DoorState record;
                    fread(&record, sizeof(struct DoorState), 1, file);
                    print_record(&record);
                }
                break;
            case 1: {
                // Чтение всех записей из файла в массив в памяти
                struct DoorState *records = malloc(records_count * sizeof(struct DoorState));
                fseek(file, 0, SEEK_SET);
                fread(records, sizeof(struct DoorState), records_count, file);

                // Сортировка массива в памяти
                qsort(records, records_count, sizeof(struct DoorState), compare_record);

                // Вывод отсортированного массива
                for (int i = 0; i < records_count; ++i) {
                    print_record(&records[i]);
                }

                // Освобождение выделенной памяти
                free(records);
                break;
            }
            case 2: {
                // Добавление новой записи
                struct DoorState new_record;
                printf("Enter new record (year month day hour minute second status code): ");
                scanf("%d %d %d %d %d %d %d %d", &new_record.year, &new_record.month, &new_record.day,
                      &new_record.hour, &new_record.minute, &new_record.second, &new_record.status,
                      &new_record.code);

                // Установка позиции для добавления новой записи
                fseek(file, 0, SEEK_END);

                // Запись новой записи в конец файла
                fwrite(&new_record, sizeof(struct DoorState), 1, file);

                // Увеличение счетчика записей
                records_count++;

                // Сортировка массива в памяти
                fseek(file, 0, SEEK_SET);
                struct DoorState *records = malloc(records_count * sizeof(struct DoorState));
                fread(records, sizeof(struct DoorState), records_count, file);
                qsort(records, records_count, sizeof(struct DoorState), compare_record);

                // Запись отсортированного массива обратно в файл
                fseek(file, 0, SEEK_SET);
                fwrite(records, sizeof(struct DoorState), records_count, file);

                // Вывод отсортированного массива
                for (int i = 0; i < records_count; ++i) {
                    print_record(&records[i]);
                }

                // Освобождение выделенной памяти
                free(records);
                break;
            }
            case 3:
                break;
            default:
                printf("n/a");
        }
    } while (choice != 3);

    fclose(file);
    return 0;
}
