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

int get_records_count_in_file(FILE *pfile);

void read_record(FILE *file, struct DoorState *record, int index) {
    fseek(file, index * sizeof(struct DoorState), SEEK_SET);
    fread(record, sizeof(struct DoorState), 1, file);
    fseek(file, 0, SEEK_SET);
}

int main() {
    char filename[256];
    char search_date[11];

    printf("Enter the filename: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("n/a");
        return 1;
    }

    int records_count = get_records_count_in_file(file);

    printf("Enter the search date (DD.MM.YYYY): ");
    scanf("%10s", search_date);

    int found = 0;
    for (int i = 0; i < records_count; ++i) {
        struct DoorState record;
        read_record(file, &record, i);

        char record_date[11];
        snprintf(record_date, sizeof(record_date), "%02d.%02d.%04d", record.day, record.month, record.year);

        if (strcmp(record_date, search_date) == 0) {
            printf("%d\n", record.code);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("n/a\n");
    }

    fclose(file);
    return 0;
}

int get_records_count_in_file(FILE *pfile) {
    fseek(pfile, 0, SEEK_END);

    long file_size = ftell(pfile);

    size_t record_size = sizeof(struct DoorState);

    int records_count = file_size / record_size;

    return records_count;
}
