#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

void output_static_arr(int arr[][NMAX], int arr_size_first, int arr_size_second);
int input_static_arr(int arr[][NMAX], int arr_size_first, int arr_size_second);
int input_arr_size(int *arr_size_first, int *arr_size_second);
int input_select_arr(int *operation);
void dynamic_arr_first_type(int ***arr, int arr_size_first, int arr_size_second);
void dynamic_arr_second_type(int ***arr, int arr_size_first, int arr_size_second);
void dynamic_arr_third_type(int ***arr, int **val_arr, int arr_size_first, int arr_size_second);
void output_dynamic_arr(int **arr, int arr_size_first, int arr_size_second);
int input_dynamic_arr(int ***arr, int arr_size_first, int arr_size_second);
void output_static_arr(int arr[][NMAX], int arr_size_first, int arr_size_second);
void detected_max(int **arr, int *result, int arr_size_first, int arr_size_second);
void detected_min(int **arr, int *result, int arr_size_first, int arr_size_second); 

int main() {
    int static_arr[NMAX][NMAX], select_arr, arr_size_first, arr_size_second;
    int **dynamic_arr, *val_arr;
    int result_max[NMAX], result_min[NMAX];
    if (input_select_arr(&select_arr) == 1) {
        printf("n/a");
        return 1;
    }

    switch (select_arr) {
        case 1:
            if (input_arr_size(&arr_size_first, &arr_size_second) == 1) {
                printf("n/a");
                return 1;
            }
            if (input_static_arr(static_arr, arr_size_first, arr_size_second) == 1) {
                printf("n/a");
                return 1;
            }
            output_static_arr(static_arr, arr_size_first, arr_size_second);
            break;
        case 2:
            if (input_arr_size(&arr_size_first, &arr_size_second) == 1) {
                printf("n/a");
                return 1;
            }
            dynamic_arr_first_type(&dynamic_arr, arr_size_first, arr_size_second);
            if (input_dynamic_arr(&dynamic_arr, arr_size_first, arr_size_second) == 1) {
                printf("n/a");
                return 1;
            }
            output_dynamic_arr(dynamic_arr, arr_size_first, arr_size_second);
            detected_max(dynamic_arr, result_max, arr_size_first, arr_size_second);
            detected_min(dynamic_arr, result_min, arr_size_first, arr_size_second);
            free(dynamic_arr);
            break;
        case 3:
            if (input_arr_size(&arr_size_first, &arr_size_second) == 1) {
                printf("n/a");
                return 1;
            }
            dynamic_arr_second_type(&dynamic_arr, arr_size_first, arr_size_second);
            if (input_dynamic_arr(&dynamic_arr, arr_size_first, arr_size_second) == 1) {
                printf("n/a");
                return 1;
            }
            output_dynamic_arr(dynamic_arr, arr_size_first, arr_size_second);
            for (int i = 0; i < arr_size_first; i++) free(dynamic_arr[i]);
            free(dynamic_arr);
            break;
        case 4:
            if (input_arr_size(&arr_size_first, &arr_size_second) == 1) {
                printf("n/a");
                return 1;
            }
            dynamic_arr_third_type(&dynamic_arr, &val_arr, arr_size_first, arr_size_second);
            if (input_dynamic_arr(&dynamic_arr, arr_size_first, arr_size_second) == 1) {
                printf("n/a");
                return 1;
            }
            output_dynamic_arr(dynamic_arr, arr_size_first, arr_size_second);
            free(dynamic_arr);
            free(val_arr);
            break;
        default:
            break;
    }
}

int input_select_arr(int *operation) {
    char ch;
    int error_check = 0;
    if (scanf("%d%c", operation, &ch) != 2 || ch != '\n' || *operation > 4 || *operation < 1) {
        error_check = 1;
    }

    return error_check;
}

int input_arr_size(int *arr_size_first, int *arr_size_second) {
    char ch1, ch2;
    int error_check = 0;
    if (scanf("%d%c %d%c", arr_size_first, &ch1, arr_size_second, &ch2) != 4 || ch1 != ' ' || ch2 != '\n') {
        error_check = 1;
    }

    return error_check;
}

int input_static_arr(int arr[][NMAX], int arr_size_first, int arr_size_second) {
    for (int i = 0; i < arr_size_first; i++) {
        for (int j = 0; j < arr_size_second; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                return 1;
            }
        }

        char ch2;
        if (scanf("%c", &ch2) != 1 || ch2 != '\n') {
            return 1;
        }
    }

    return 0;
}

void output_static_arr(int arr[][NMAX], int arr_size_first, int arr_size_second) {
    for (int i = 0; i < arr_size_first; i++) {
        for (int j = 0; j < arr_size_second; j++) {
            printf("%d", arr[i][j]);

            if (j + 1 < arr_size_second) {
                printf(" ");
            }
        }

        if (i + 1 < arr_size_first) printf("\n");
    }
}

int input_dynamic_arr(int ***arr, int arr_size_first, int arr_size_second) {
    for (int i = 0; i < arr_size_first; i++) {
        for (int j = 0; j < arr_size_second; j++) {
            int l;
            if (scanf("%d", &l) != 1) {
                return 1;
            }
            (*arr)[i][j] = l;
        }

        char ch2;
        if (scanf("%c", &ch2) != 1 || ch2 != '\n') {
            return 1;
        }
    }

    return 0;
}

void output_dynamic_arr(int **arr, int arr_size_first, int arr_size_second) {
    for (int i = 0; i < arr_size_first; i++) {
        for (int j = 0; j < arr_size_second; j++) {
            printf("%d", arr[i][j]);

            if (j + 1 < arr_size_second) {
                printf(" ");
            }
        }
        if (i + 1 < arr_size_first) printf("\n");
    }
}

void dynamic_arr_first_type(int ***arr, int arr_size_first, int arr_size_second) {
    *arr = malloc(arr_size_first * arr_size_second * sizeof(int) + arr_size_second * sizeof(int *));
    int *p = (int *)((*arr) + arr_size_first);

    for (int i = 0; i < arr_size_first; i++) {
        (*arr)[i] = p + arr_size_second * i;
    }
}

void dynamic_arr_second_type(int ***arr, int arr_size_first, int arr_size_second) {
    (*arr) = malloc(arr_size_first * sizeof(int *));

    for (int i = 0; i < arr_size_first; i++) {
        (*arr)[i] = malloc(arr_size_second * sizeof(int));
    }
}

void dynamic_arr_third_type(int ***arr, int **val_arr, int arr_size_first, int arr_size_second) {
    (*arr) = malloc(arr_size_first * sizeof(int *));
    (*val_arr) = malloc(arr_size_second * arr_size_first * sizeof(int));

    for (int i = 0; i < arr_size_second; i++) {
        (*arr)[i] = *val_arr + arr_size_second * i;
    }
}

void detected_max(int **arr, int *result, int arr_size_first, int arr_size_second) {
    int count = 0;

    for (int i = 0; i < arr_size_first; i++) {
        int max = arr[i][0];
        for (int j = 0; j < arr_size_second; j++) {
            if (max < arr[i][j]) max = arr[i][j];
        }
        result[count] = max;
        count += 1;
    }

    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("%d", result[i]);
        
        if (i + 1 < count) {
            printf(" ");
        }
    }
}

void detected_min(int **arr, int *result, int arr_size_first, int arr_size_second) {
    int count = 0;

    for (int i = 0; i < arr_size_second; i++) {
        int min = arr[i][0];
        for (int j = 0; j < arr_size_first; j++) {
            if (min > arr[j][i]) min = arr[j][i];
        }
        result[count] = min;
        count += 1;
    }

    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("%d", result[i]);
        
        if (i + 1 < count) {
            printf(" ");
        }
    }
}