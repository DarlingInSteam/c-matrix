#include <stdio.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void output(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(&picture_data[0][0], picture, N, M);

    make_picture(picture, N, M);
    output(picture, N, M);
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
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[N - 1][i] = frame_w[i];
        picture[(N - 1) / 2][i] = frame_w[i];
    }

    for (int i = 7; i < 12; i++) {
        if (i >= 2) {
            picture[1][i] = sun_data[0][i - 7];
            picture[2][i] = sun_data[1][i - 7];
            picture[3][i] = sun_data[2][i - 7];
            picture[4][i] = sun_data[3][i - 7];
        }
    }

    for (int i = 1; i < 6; i++) {
        if (i == 3 || i == 4) {
            picture[2][i] = tree_foliage[0];
            picture[5][i] = tree_foliage[0];
            picture[6][i] = tree_trunk[0];
            picture[8][i] = tree_trunk[0];
            picture[9][i] = tree_trunk[0];
        }

        if (i >= 2) {
            picture[3][i] = tree_foliage[0];
            picture[4][i] = tree_foliage[0];
            picture[10][i] = tree_trunk[0];
        }
    }

    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][M - 1] = frame_h[i];
        picture[i][(M - 1) / 2] = frame_h[i];
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

void output(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", picture[i][j]);

            if (j + 1 < m) {
                printf(" ");
            }
        }
        if (i + 1 < n) printf("\n");
    }
}