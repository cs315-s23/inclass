void ashift_c(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = arr[i] >> 3;
    }
}
