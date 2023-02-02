int count_c(int val) {
    int count = 0;

    while (val > 0) {
        count++;
        val--;
    }

    return count;
}
