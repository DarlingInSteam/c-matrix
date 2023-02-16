#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void dynamic_arr_second_type(int ***arr, int arr_size_first, int arr_size_second);
void output_dynamic_arr(int **arr, int arr_size_first, int arr_size_second);
int input_dynamic_arr(int ***arr, int arr_size_first, int arr_size_second);
int input_select_arr(int *operation);
int input_arr_size(int *arr_size_first, int *arr_size_second);
void sum(int **arr1, int **arr2, int arr_size_first, int arr_size_second, int ***result);
void dynamic(int ***a, int n, int b);
int mul(int **arr1, int **arr2, int arr_size_first, int arr_size_second, int arr_size_first1,
        int arr_size_second1, int ***result);
void transp(int **arr1, int arr_size_first, int arr_size_second, int ***result);

int main() {
    int **dynamic_array_first, **dynamic_array_second, **result;
    int size_array_first, size_array_second, size_array_first1, size_array_second1;
    int operation;

    if (input_select_arr(&operation) == 1) {
        printf("n/a");
        return 1;
    }

    switch (operation) {
        case 1:
            if (input_arr_size(&size_array_first, &size_array_second) == 1) {
                printf("n/a");
                break;
            }
            dynamic_arr_second_type(&dynamic_array_first, size_array_first, size_array_second);
            if (input_dynamic_arr(&dynamic_array_first, size_array_first, size_array_second) == 1) {
                printf("n/a");
                break;
            }
            if (input_arr_size(&size_array_first1, &size_array_second1) == 1) {
                printf("n/a");
                break;
            }
            dynamic_arr_second_type(&dynamic_array_second, size_array_first1, size_array_second1);
            if (input_dynamic_arr(&dynamic_array_second, size_array_first1, size_array_second1) == 1) {
                printf("n/a");
                break;
            }
            sum(dynamic_array_first, dynamic_array_second, size_array_first, size_array_second, &result);
            output_dynamic_arr(result, size_array_first, size_array_second);
            break;
        case 2:
            if (input_arr_size(&size_array_first, &size_array_second) == 1) {
                printf("n/a");
                break;
            }
            dynamic_arr_second_type(&dynamic_array_first, size_array_first, size_array_second);
            if (input_dynamic_arr(&dynamic_array_first, size_array_first, size_array_second) == 1) {
                printf("n/a");
                break;
            }
            if (input_arr_size(&size_array_first1, &size_array_second1) == 1) {
                printf("n/a");
                break;
            }
            dynamic_arr_second_type(&dynamic_array_second, size_array_first1, size_array_second1);
            if (input_dynamic_arr(&dynamic_array_second, size_array_first1, size_array_second1) == 1) {
                printf("n/a");
                break;
            }
            if (mul(dynamic_array_first, dynamic_array_second, size_array_first, size_array_second,
                    size_array_first1, size_array_second1, &result) == 1) {
                printf("n/a");
                break;
            }
            output_dynamic_arr(result, size_array_first, size_array_second1);

            break;
        case 3:
            if (input_arr_size(&size_array_first, &size_array_second) == 1) {
                printf("n/a");
                break;
            }
            dynamic_arr_second_type(&dynamic_array_first, size_array_first, size_array_second);
            if (input_dynamic_arr(&dynamic_array_first, size_array_first, size_array_second) == 1) {
                printf("n/a");
                break;
            }

            transp(dynamic_array_first, size_array_first, size_array_second, &result);

            output_dynamic_arr(result, size_array_second, size_array_first);
    }

    for (int i = 0; i < size_array_first; i++) free(dynamic_array_first[i]);
    free(dynamic_array_first);
    for (int i = 0; i < size_array_second; i++) free(dynamic_array_second[i]);
    free(dynamic_array_second);
    for (int i = 0; i < size_array_first; i++) free(result[i]);
    free(result);
}

void dynamic_arr_second_type(int ***arr, int arr_size_first, int arr_size_second) {
    (*arr) = malloc(arr_size_first * sizeof(int *));

    for (int i = 0; i < arr_size_first; i++) {
        (*arr)[i] = malloc(arr_size_second * sizeof(int));
    }
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

int input_select_arr(int *operation) {
    char ch;
    int error_check = 0;
    if (scanf("%d%c", operation, &ch) != 2 || ch != '\n' || *operation > 3 || *operation < 1) {
        error_check = 1;
    }

    return error_check;
}

int input_arr_size(int *arr_size_first, int *arr_size_second) {
    char ch1, ch2;
    int error_check = 0;
    if (scanf("%d%c %d%c", arr_size_first, &ch1, arr_size_second, &ch2) != 4 || ch1 != ' ' || ch2 != '\n' ||
        *arr_size_first <= 0 || *arr_size_second <= 0) {
        error_check = 1;
    }

    return error_check;
}

void sum(int **arr1, int **arr2, int arr_size_first, int arr_size_second, int ***result) {
    dynamic(result, arr_size_first, arr_size_second);

    for (int i = 0; i < arr_size_first; i++) {
        for (int j = 0; j < arr_size_second; j++) {
            (*result)[i][j] = 0;
            (*result)[i][j] += arr1[i][j] + arr2[i][j];
        }
    }
}

int mul(int **arr1, int **arr2, int arr_size_first, int arr_size_second, int arr_size_first1,
        int arr_size_second1, int ***result) {
    dynamic(result, arr_size_first, arr_size_second1);

    if (arr_size_second == arr_size_first1) {
        for (int i = 0; i < arr_size_first; i++) {
            for (int j = 0; j < arr_size_second1; j++) {
                (*result)[i][j] = 0;
                for (int u = 0; u < arr_size_first1; u++) {
                    (*result)[i][j] += arr1[i][u] * arr2[u][j];
                }
            }
        }
    } else {
        return 1;
    }

    return 0;
}

void transp(int **arr1, int arr_size_first, int arr_size_second, int ***result) {
    dynamic(result, arr_size_second, arr_size_first);

    for (int i = 0; i < arr_size_first; i++) {
        for (int j = 0; j < arr_size_second; j++) {
            (*result)[j][i] = 0;

            (*result)[j][i] = arr1[i][j];
        }
    }
}

void dynamic(int ***a, int n, int b) {
    (*a) = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) (*a)[i] = malloc(b * sizeof(int));
}