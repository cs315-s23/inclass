void ashift_c(int *arr, int count) {
    for (int i = 0; i < count; i++) {
        arr[i] = arr[i] >> 2; // down by 2 === /4
    }
}
