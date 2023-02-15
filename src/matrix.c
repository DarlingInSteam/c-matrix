#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int output_static_arr(int arr[][NMAX], int arr_size_first, int arr_size_second);
int input_static_arr(int arr[][NMAX], int arr_size_first, int arr_size_second);
int input_static_arr_size(int *arr_size_first, int *arr_size_second);
int input_select_arr(int *operation);

int main() {
    int static_arr[NMAX][NMAX], select_arr, dynamic_arr_size_first, dynamic_arr_size_second, static_arr_size_first, static_arr_size_second;
    int *dynamic_arr_first, *dynamic_arr_second, *dynamic_arr_third;
    
    if (input_select_arr(&select_arr) == 1) {
        printf("n/a");
        return 1;
    }

    switch(select_arr) {
        case 1:
            if (input_static_arr_size(&static_arr_size_first, &static_arr_size_second) == 1) {
                printf("n/a");
                return 1;
            }
            input_static_arr(static_arr, static_arr_size_first, static_arr_size_second);
            output_static_arr(static_arr, static_arr_size_first, static_arr_size_second);

    }
}

int input_select_arr(int *operation) {
    char ch;
    int error_check = 0;
    if (scanf("%d%c", operation, &ch) != 2 || ch != '\n') {
        error_check = 1;
    }

    return error_check;
}

int input_static_arr_size(int *arr_size_first, int *arr_size_second) {
    char ch1, ch2;
    int error_check = 0;
    if (scanf("%d%c %d%c", arr_size_first, &ch1, arr_size_second, &ch2) != 4 || ch1 != ' ' || ch2 != '\n') {
        error_check = 1;
    }

    return error_check;
}

int input_static_arr(int arr[][NMAX], int arr_size_first, int arr_size_second) {
    char ch;
    int error_check = 0;

    for (int i = 0; i < arr_size_first; i++) {
        for (int j = 0; j < arr_size_second; j++) {
            if (scanf("%d", &arr[i][j]) != 2) {
                
            }
        }
    }
}

int output_static_arr(int arr[][NMAX], int arr_size_first, int arr_size_second) {

}