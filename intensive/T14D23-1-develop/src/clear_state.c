#define _XOPEN_SOURCE
#include <time.h>

#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <filename> <start_date> <end_date>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    FILE *file = fopen(filename, "rb+");
    if (!file) {
        perror("n/a");
        return 1;
    }

    // Подсчет количества записей в файле
    fseek(file, 0, SEEK_END);
    int records_count = ftell(file) / sizeof(struct DoorState);
    fseek(file, 0, SEEK_SET);

    // Чтение временных меток начала и конца удаления
    struct tm start_date, end_date;
    strptime(argv[2], "%d.%m.%Y", &start_date);
    strptime(argv[3], "%d.%m.%Y", &end_date);

    // Перевод временных меток в секунды с начала эпохи
    time_t start_time = mktime(&start_date);
    time_t end_time = mktime(&end_date);

    if (start_time == -1 || end_time == -1) {
        perror("n/a");
        fclose(file);
        return 1;
    }

    int records_to_keep = 0;

    // Подсчет записей, которые нужно сохранить
    for (int i = 0; i < records_count; ++i) {
        struct DoorState record;
        fread(&record, sizeof(struct DoorState), 1, file);

        struct tm record_date = {.tm_year = record.year - 1900,
                                 .tm_mon = record.month - 1,
                                 .tm_mday = record.day,
                                 .tm_hour = record.hour,
                                 .tm_min = record.minute,
                                 .tm_sec = record.second};

        time_t record_time = mktime(&record_date);

        if (record_time >= start_time && record_time <= end_time) {
            // Запись не попадает в интервал, увеличиваем счетчик
            records_to_keep++;
        }
    }

    // Позиционирование в начало файла
    fseek(file, 0, SEEK_SET);

    // Создание временного массива для хранения записей, которые нужно сохранить
    struct DoorState *records_to_keep_array = malloc(records_to_keep * sizeof(struct DoorState));
    int index = 0;

    // Считывание и сохранение записей
    for (int i = 0; i < records_count; ++i) {
        struct DoorState record;
        fread(&record, sizeof(struct DoorState), 1, file);

        struct tm record_date = {.tm_year = record.year - 1900,
                                 .tm_mon = record.month - 1,
                                 .tm_mday = record.day,
                                 .tm_hour = record.hour,
                                 .tm_min = record.minute,
                                 .tm_sec = record.second};

        time_t record_time = mktime(&record_date);

        if (record_time < start_time || record_time > end_time) {
            // Запись не попадает в интервал, копируем ее в массив
            memcpy(&records_to_keep_array[index], &record, sizeof(struct DoorState));
            index++;
        }
    }

    // Отсечение оставшихся записей в файле
    ftruncate(fileno(file), 0);

    // Запись отфильтрованных записей обратно в файл
    fwrite(records_to_keep_array, sizeof(struct DoorState), records_to_keep, file);

    // Освобождение ресурсов
    free(records_to_keep_array);
    fclose(file);

    return 0;
}
