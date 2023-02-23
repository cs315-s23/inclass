#include <stdlib.h>
#include <stdio.h>

#define ARR_LEN 10

void ashift_c(int*, int);
void ashift_s(int*, int);

void load_arr(int *arr, int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
}

void print_arr(int *arr, int len, char *label) {
    printf("%s:", label);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int arr[ARR_LEN];
    int len = argc - 1;

    load_arr(arr, argc, argv);
    ashift_c(arr, len);
    print_arr(arr, len, "C");

    load_arr(arr, argc, argv);
    ashift_s(arr, len);
    print_arr(arr, len, "Asm");
}
