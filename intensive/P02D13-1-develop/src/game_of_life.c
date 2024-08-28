#include <stdio.h>
#include <stdlib.h>

void draw_logo();
int initial_menu(int initial_states_array);
int load_file(int** matrix_array, int map_width, int file_id);
void draw_map(int** matrix_array, int map_width, int map_height, int update_speed);
void update_positions(int map_width, int map_height, int** matrix_array);
void check_alive_pixels(int** matrix_array, int** ram_array, int map_width, int map_height);
void update_map_array(int** matrix_array, int i, int j, int foundAlive);
int minus_i(int i, int map_height);
int plus_i(int i, int map_height);
int minus_j(int j, int map_width);
int plus_j(int j, int map_width);

int main() {
    int map_width = 80 - 2;
    int map_height = 25 - 2;

    int update_speed = 16000;

    int selected_init_id = -1;

    int** matrix_array = malloc(map_height * sizeof(int*));
    for (int i = 0; i < map_height; i++) {
        matrix_array[i] = malloc(map_width * sizeof(int));
    }

    printf("\033[2J\033[H");

    selected_init_id = initial_menu(5);
    while (selected_init_id == -1) {
        printf("\033[2J\033[H");
        scanf("%*[^\n]%*c");
        selected_init_id = initial_menu(5);
    }

    if (load_file(matrix_array, map_width, selected_init_id) == 1) {
        return 1;
    }

    int is_alive = 1;
    while (is_alive) {
        printf("\033[2J\033[H");
        draw_map(matrix_array, map_width, map_height, update_speed);
        update_positions(map_width, map_height, matrix_array);

        const char* bashScript = "./get_pressed_key.sh";
        FILE* pipe = popen(bashScript, "r");
        int key_code = pclose(pipe);
        if (key_code == 5376 && update_speed < 32000) {
            update_speed *= 2;
        } else if (key_code == 5120 && update_speed > 4000) {
            update_speed /= 2;
        } else if (key_code == 2560) {
            is_alive = 0;
        }

        for (int c = 1; c <= update_speed; c++) {
            for (int d = 1; d <= update_speed; d++) {
            }
        }
    }

    for (int i = 0; i < map_height; i++) {
        free(matrix_array[i]);
    }
    free(matrix_array);

    return 0;
}

void draw_logo() {
    printf("       ________                                _____  .__  .__  _____       \n");
    printf("      /  _____/_____    _____   ____     _____/ ____\\ |  | |__|/ ____\\____  \n");
    printf("     /   \\  ___\\__  \\  /     \\_/ __ \\   /  _ \\   __\\  |  | |  \\   __\\/ __ \\ \n");
    printf("     \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  (  <_> )  |    |  |_|  ||  | \\  ___/ \n");
    printf("      \\______  (____  /__|_|  /\\___  >  \\____/|__|    |____/__||__|  \\___  >\n");
    printf("             \\/     \\/      \\/     \\/                                    \\/ \n");
}

int initial_menu(int initial_states_array_size) {
    draw_logo();

    printf("\n\n Select Initial state of LIFE:\n");
    for (int i = 0; i != initial_states_array_size; i++) {
        printf("- Initial state %d\n", i + 1);
    }

    printf("Select state: ");
    int selected_state_id = -1;
    if (scanf("%d", &selected_state_id) == 1 && selected_state_id > 0 && selected_state_id <= 5) {
        return selected_state_id;
    }
    return -1;
}

int load_file(int** matrix_array, int map_width, int file_id) {
    char init_file[23];
    sprintf(init_file, "./presets/init_%d.txt", file_id);

    FILE* file = fopen(init_file, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char character;
    int i = 0;
    int j = 0;
    while ((character = fgetc(file)) != EOF) {
        if (character != '\n') {
            matrix_array[i][j] = character - '0';
            j++;
            if (j == map_width) {
                i++;
                j = 0;
            }
        }
    }

    fclose(file);

    return 0;
}

void update_positions(int map_width, int map_height, int** matrix_array) {
    int** ram_array = malloc(map_height * sizeof(int*));
    for (int i = 0; i < map_height; i++) {
        ram_array[i] = malloc(map_width * sizeof(int));
        for (int j = 0; j < map_width; j++) {
            ram_array[i][j] = matrix_array[i][j];
        }
    }

    check_alive_pixels(matrix_array, ram_array, map_width, map_height);

    for (int i = 0; i < map_height; i++) {
        free(ram_array[i]);
    }
    free(ram_array);
}

void check_alive_pixels(int** matrix_array, int** ram_array, int map_width, int map_height) {
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            int found = 0;
            if (ram_array[minus_i(i, map_height)][minus_j(j, map_width)] == 1) {
                found++;
            }
            if (ram_array[minus_i(i, map_height)][j] == 1) {
                found++;
            }
            if (ram_array[minus_i(i, map_height)][plus_j(j, map_width)] == 1) {
                found++;
            }
            if (ram_array[i][minus_j(j, map_width)] == 1) {
                found++;
            }
            if (ram_array[i][plus_j(j, map_width)] == 1) {
                found++;
            }
            if (ram_array[plus_i(i, map_height)][minus_j(j, map_width)] == 1) {
                found++;
            }
            if (ram_array[plus_i(i, map_height)][j] == 1) {
                found++;
            }
            if (ram_array[plus_i(i, map_height)][plus_j(j, map_width)] == 1) {
                found++;
            }

            update_map_array(matrix_array, i, j, found);
        }
    }
}

void update_map_array(int** matrix_array, int i, int j, int foundAlive) {
    if (matrix_array[i][j] == 1) {
        if (foundAlive == 3 || foundAlive == 2) {
            matrix_array[i][j] = 1;
        } else if (foundAlive < 2) {
            matrix_array[i][j] = 0;
        } else {
            matrix_array[i][j] = 0;
        }
    } else if (matrix_array[i][j] == 0 && foundAlive == 3) {
        matrix_array[i][j] = 1;
    }
}

int minus_i(int i, int map_height) {
    if (i == 0) {
        return map_height - 1;
    } else {
        return i - 1;
    }
}

int plus_i(int i, int map_height) {
    if (i == map_height - 1) {
        return 0;
    } else {
        return i + 1;
    }
}

int minus_j(int j, int map_width) {
    if (j == 0) {
        return map_width - 1;
    } else {
        return j - 1;
    }
}

int plus_j(int j, int map_width) {
    if (j == map_width - 1) {
        return 0;
    } else {
        return j + 1;
    }
}

void draw_map(int** matrix_array, int map_width, int map_height, int update_speed) {
    draw_logo();

    for (int i = 0; i < map_width + 2; i++) {
        printf("-");
    }
    printf("\n");

    for (int i = 0; i < map_height; i++) {
        printf("|");
        for (int j = 0; j < map_width; j++) {
            if (matrix_array[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }

    for (int i = 0; i < map_width + 2; i++) {
        printf("-");
    }
    printf("\n - Use K and M keys to change Speed - \n");
    if (update_speed == 32000) {
        printf("   Current Speed: x0.5\n");
    } else if (update_speed == 16000) {
        printf("   Current Speed: x1\n");
    } else if (update_speed == 8000) {
        printf("   Current Speed: x2\n");
    } else if (update_speed == 4000) {
        printf("   Current Speed: x4\n");
    }

    printf("\n\nPress 'X' to quit!\n");
}