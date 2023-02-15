#include <stdio.h>
#include <stdlib.h>

int *input(int *n);
void output(int *a, int n);
void sorting_array(int *a, int n);

int main() {
    int n;
    int *data = input(&n);
    if (data == NULL) {
        printf("n/a");
        return 1;
    } else {
        sorting_array(data, n);
        output(data, n);
    }
}

int *input(int *n) {
    char ch;

    if (scanf("%d%c", n, &ch) != 2 || ch != '\n') {
        return NULL;
    }

    int *buf = (int *)malloc(*n * sizeof(int));

    for (int p = 0; p < *n; p++) {
        if (scanf("%d", &buf[p]) != 1) {
            return NULL;
        }
    }

    char ch2;

    if (scanf("%c", &ch2) != 1 || ch2 != '\n') {
        return NULL;
    }

    return buf;
}

void output(int *a, int n) {
    for (int p = 0; p < n; p++) {
        printf("%d", a[p]);

        if (n - 1 > p) {
            printf(" ");
        }
    }
}

void sorting_array(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(a + j) < *(a + i)) {
                int tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }
}