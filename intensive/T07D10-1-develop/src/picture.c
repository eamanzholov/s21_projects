#include <stdio.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(picture_data, picture, N, M);

    make_picture(picture, N, M);

    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);

    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
    }

    for (int i = 1; i < n; i++) {
        picture[i][0] = frame_h[i - 1];
        picture[i][6] = frame_h[i - 1];
        picture[i][m - 1] = frame_h[i - 1];
    }

    for (int i = 2; i < 6; i++) {
        for (int j = 2; j < 6; j++) {
            picture[i][j] = tree_foliage[i - 2];
        }
    }
    picture[2][2] = 0;
    picture[2][5] = 0;
    picture[5][2] = 0;
    picture[5][5] = 0;

    for (int i = 6; i < 10; i++) {
        for (int j = 3; j < 5; j++) {
            int tree_trunk_1 = 7;
            picture[i][j] = tree_trunk_1;
        }
    }
    for (int j = 2; j < 6; j++) {
        picture[10][j] = tree_trunk[j - 2];
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 7; j < 12; j++) {
            picture[i][j] = sun_data[i - 1][j - 7];
        }
    }
    for (int i = 7; i < n; i += 7) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = frame_w[j];
        }
    }

    // Output the picture
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", picture[i][j]);
        }
        printf("\n");
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}
