#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10

void ashift_c(int*, int);
void ashift_s(int*, int);

int load_arr(int *arr, int argc, char **argv) {
    int i;
    for (i = 1; i < argc; i++) {
        arr[i - 1] =  atoi(argv[i]);
    }
    return i - 1;
}

void print_arr(int *arr, int count, char *label) {
    printf("%s: ", label);
    for (int i = 0; i < count; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char **argv) {
    int arr[MAX_NUMS];
    int count;
    
    count = load_arr(arr, argc, argv);
    ashift_c(arr, count);
    print_arr(arr, count, "C");
    
    load_arr(arr, argc, argv);
    ashift_s(arr, count);
    print_arr(arr, count, "Asm");

    return 0;
}
