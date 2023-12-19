#include <stdio.h>

void add1_c(int*, int);
void add1_s(int*, int);

void print_arr(int *arr, int len) {
    for (int i = 0; i < len; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

#define LEN 5

int main() {
    int arr[LEN] = {1,2,3,4,5};
    add1_c(arr, LEN);
    printf("C: ");
    print_arr(arr, 5);

    int arr2[LEN] = {1,2,3,4,5};
    add1_s(arr2, LEN);
    printf("Asm: ");
    print_arr(arr2, 5);

    return 0;
}
